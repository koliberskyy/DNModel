#include "mapwidget.h"

MapWidget::MapWidget(QWidget *parent)
    : QGLWidget(parent),
      PI(3.14159265),
      waveLength(0.20)
{
    rls = new RLS(0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0);
    tle = new Tle("UK-DMC 2                ",
                                    "1 35683U 09041C   12289.23158813  .00000484  00000-0  89219-4 0  5863",
                                    "2 35683  00.0221 000.3682 0001499 000.5295 000.6088 00.99819587172294");
    currentTime = new DateTime(tle->Epoch());
    vSE.clear();
}

MapWidget::~MapWidget()
{
    delete tle;
    delete rls;
}

void MapWidget::initializeGL()
{
    qglClearColor(Qt::white);
    glOrtho(-180,180,-90,90,1,0);
    genTextures();
}

void MapWidget::resizeGL(int w, int h)
{
    glViewport(0,0,w,h);
}

void MapWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);
    drawBackground();
    glPointSize(2);
    drawViewZoneDegreesIn(*rls);
    drawTrace(*tle, *rls, *currentTime);
    emit ESACalculated(vESA, vAngle);
}

double MapWidget::locaAngle(Eci ka_tmp, double latitude_tmp, double longtitude_tmp, double altitude_tmp)
{
    Eci rls(0,latitude_tmp, longtitude_tmp, altitude_tmp);
    Vector R = ka_tmp.Position() - rls.Position();
    Vector V = ka_tmp.Velocity();
    double angle(0);
    angle =  Util::RadiansToDegrees(acos((R.x * V.x + R.y * V.y + R.z * V.z)/(R.Magnitude() * V.Magnitude())));
    return angle;
}

double MapWidget::ESA(double radius)
{
    if(radius <=0)
        return 0;
    else
        return PI * radius * radius;
}

double MapWidget::ESA(double radius0, double radius1, double width, double locationAngle)
{
    if(radius0<=0 || radius1<=0 || width <=0)
        return 0;
    double locationAngleRad = Util::DegreesToRadians(locationAngle);
    double k                = 2 * PI / waveLength;//ok
    double x                = k * width * cos(locationAngleRad);//ok
    double f1               = sin(x)/x;//ok
    double ESA_MAX          = 2 * PI * radius0 * width * width / waveLength;//ok
    double esa              = sqrt(ESA_MAX)  * f1 * sqrt(sin(locationAngleRad));
    if(esa > 0)
        return esa;
    else
        return -esa;
}

double MapWidget::ESA(double height, double width, double locationAngle)
{
    if(height<=0 || width<=0)
        return 0;
    double locationAngleRad = Util::DegreesToRadians(locationAngle);
    double k                = 2 * PI / waveLength;
    double x                = k * width * cos(locationAngleRad);
    double y                = k * height * cos(locationAngleRad);
    double f1               = sin(x)/x;
    double f2               = cos(y)/y;
    double ESA_MAX          = (4 * PI * height * height * width * width) / (waveLength * waveLength);
    double esa              = sqrt(ESA_MAX) * f1 * f2 * sin(locationAngleRad);
    if(esa > 0)
        return esa;
    else
        return -esa;
}

void MapWidget::calculateESA(Eci eci_tmp, double latitude_tmp, double longtitude_tmp, double altitude_tmp)
{
    double locationAngle = locaAngle(eci_tmp, latitude_tmp, longtitude_tmp, altitude_tmp);
    simpleElement se;
    double sumESA(0);
    for(unsigned int i = 0; i<vSE.size(); i++)
    {
        se = vSE[i];
        switch (se.elementType)
        {
        case 0:
            sumESA+= ESA(se.arg0);
            break;
        case 1:
            sumESA+= ESA(se.arg0, se.arg0, se.arg1,locationAngle);
            break;
        case 2:
            sumESA+= ESA(se.arg0, se.arg1, locationAngle);
            break;
        }
    }
    vESA.push_back(sumESA);
    vAngle.push_back(locationAngle);
}

void MapWidget::genTextures()
{
    QString *filename = new QString;
           *filename = "EartMap3D.png";

    GLuint textureId = bindTexture(QPixmap(*filename), GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureId);
}

void MapWidget::drawBackground()
{
    qglColor(Qt::white);
    glEnable(GL_TEXTURE_2D);
        glBegin(GL_QUADS);
            glTexCoord2d(0, 1); glVertex2d(-180, 90);
            glTexCoord2d(1, 1); glVertex2d( 180, 90);
            glTexCoord2d(1, 0); glVertex2d( 180,-90);
            glTexCoord2d(0, 0); glVertex2d(-180,-90);
        glEnd();
    glDisable(GL_TEXTURE_2D);
}

void MapWidget::drawViewZoneDegreesIn(double latitude, double longtitude, double elevationMin, double elevationMax, double azimuthMin, double azimuthMax, double rangeMin, double rangeMax)
{
    drawViewZoneRadianIn(Util::DegreesToRadians(latitude),
                         Util::DegreesToRadians(longtitude),
                         Util::DegreesToRadians(elevationMin),
                         Util::DegreesToRadians(elevationMax),
                         Util::DegreesToRadians(azimuthMin),
                         Util::DegreesToRadians(azimuthMax),
                         rangeMin,
                         rangeMax);
}

void MapWidget::drawViewZoneDegreesIn(RLS rls)
{
    drawViewZoneDegreesIn(rls.latitude,
                          rls.longtitude,
                          rls.elevationMin,
                          rls.elevationMax,
                          rls.azimuthMin,
                          rls.azimuthMax,
                          rls.rangeMin,
                          rls.rangeMax);
}

void MapWidget::drawViewZoneRadianIn(double latitude, double longtitude, double elevationMin, double elevationMax, double azimuthMin, double azimuthMax, double rangeMin, double rangeMax)
{

    qglColor(Qt::blue);
    for(double az=azimuthMin; az<azimuthMax; az+=0.01)
    {
        drawViewZonePointRadianIn(latitude, longtitude, elevationMin, az, rangeMin);
        drawViewZonePointRadianIn(latitude, longtitude, elevationMin, az, rangeMax);
    }
    elevationMax++;
    elevationMin--;
}

void MapWidget::drawViewZonePointRadianIn(double latitude, double longtitude, double elevation, double azimuth, double range)
{
    double r = 6371; //km

    double x, y, z;
    x = range * cos(elevation) * cos(azimuth);
    y = range * sin(elevation);
    z = range * cos(elevation) * sin(azimuth);

    double cx, cy, cz;
    cx = -x * sin(longtitude) * cos(latitude) + (y+r) * cos(longtitude) * cos(latitude) - z * sin(latitude);
    cy = -x * sin(longtitude) * sin(latitude) + (y+r) * cos(longtitude) * sin(latitude) + z * cos(latitude);
    cz =  x * cos(longtitude) + (y+r) * sin(longtitude);

    double D  = sqrt(cx * cx + cy * cy + cz * cz);
    double Dm = sqrt(cx * cx + cy * cy);
    double rlsLatitude(0), rlsLongtitude(0);
    if(cy >= 0)
    {
        rlsLongtitude = Util::RadiansToDegrees(acos(cx/Dm));
    }
    else
    {
        rlsLongtitude = Util::RadiansToDegrees(-acos(cx/Dm));
    }
    rlsLatitude = Util::RadiansToDegrees(asin(cz/D));
    drawPoint2d(rlsLongtitude, rlsLatitude);
}

void MapWidget::drawPoint2d(double x, double y)
{
    glBegin(GL_POINTS);
    glVertex2d(x,y);
    glEnd();
}

void MapWidget::drawTrace(Tle tle, RLS rls, DateTime dateTime)
{
    vESA.clear();
    vAngle.clear();
    qglColor(Qt::red);
    SGP4    sgp(tle);
    DateTime        date0;
    DateTime        date1;
    Eci             eci = sgp.FindPosition(dateTime);
    Eci             eci1 = sgp.FindPosition(dateTime);
    CoordGeodetic   geo = eci.ToGeodetic();
    CoordGeodetic   geo1;
    qglColor(Qt::white);
    //Рисование положения КА
    glPointSize(15);
    drawPoint2d(Util::RadiansToDegrees(geo.longitude),
                Util::RadiansToDegrees(geo.latitude));
    glPointSize(2);
    //показывает был ли КА внутри ЗО
    bool onZoneTrigger(0);
    //bool onZoneTrigger1(0);
    // рисование трассы в обе стороны от положения КА на 200*60 секунд
    for(double dT=0; dT<200*60; dT++)
    {
        date0   = dateTime.AddSeconds( dT);
        date1   = dateTime.AddSeconds(-dT);
        eci     = sgp.FindPosition(date0);
        eci1    = sgp.FindPosition(date1);
        geo     = eci.ToGeodetic();
        geo1    = eci1.ToGeodetic();
        //при попадании в зону обзора "rls" трасса рисуется зелёным цветом
        if(isVisibleDegreesIn(eci,rls))
        {
            if(onZoneTrigger == 0)
            {
                onZoneTrigger = 1;
                emit inside(date0);
            }
            qglColor(Qt::green);
            //!!!!!!!
            calculateESA(eci,rls.latitude,rls.longtitude,0.05);
        }
        else
        {
            if(onZoneTrigger == 1)
            {
                onZoneTrigger = 0;
                emit outside(date0);
            }
            qglColor(Qt::red);
        }
        drawPoint2d(Util::RadiansToDegrees(geo.longitude),
                    Util::RadiansToDegrees(geo.latitude));
        //задний виток
//        if(isVisibleDegreesIn(eci1,rls))
//        {
//            if(onZoneTrigger1 == 0)
//            {
//                onZoneTrigger1 = 1;
//                emit outside(date1);
//            }
//            qglColor(Qt::green);
//        }
//        else
//        {
//            if(onZoneTrigger1 == 1)
//            {
//                onZoneTrigger1 = 0;
//                emit inside(date1);
//            }
//            qglColor(Qt::red);
//        }
//        drawPoint2d(Util::RadiansToDegrees(geo1.longitude),
//                    Util::RadiansToDegrees(geo1.latitude));
    }
}

void MapWidget::drawTrase(Tle tle_t, DateTime currTime)
{
    delete tle;
    delete currentTime;
    tle         = new Tle(tle_t);
    currentTime = new DateTime(currTime);
    updateGL();
}

void MapWidget::drawRLS(RLS rls_t)
{
    delete rls;
    rls = new RLS(rls_t);
    updateGL();
}



QDateTime MapWidget::getEpoch()
{
    DateTime dt = tle->Epoch();
    QDate date;
    date.setDate(dt.Year(), dt.Month(), dt.Day());
    QTime time;
    time.setHMS(dt.Hour(), dt.Minute(), dt.Second());
    return QDateTime(date, time);
}

bool MapWidget::isVisibleDegreesIn(Eci eci, double latitude, double longtitude, double elevationMin, double elevationMax, double azimuthMin, double azimuthMax, double rangeMin, double rangeMax)
{
    Observer obs(longtitude,latitude, 0.05);
    CoordTopocentric topo = obs.GetLookAngle(eci);
    double AZ = Util::RadiansToDegrees(topo.azimuth);
    double UM = Util::RadiansToDegrees(topo.elevation);
    double D = topo.range;
    if(AZ>azimuthMin && AZ<azimuthMax &&
            UM>elevationMin && UM<elevationMax &&
            D>rangeMin && D<rangeMax)
        return true;
    else
        return false;
}
bool MapWidget::isVisibleDegreesIn(Eci eci, RLS rls)
{
    return isVisibleDegreesIn(eci, rls.latitude, rls.longtitude,
                              rls.elevationMin, rls.elevationMax,
                              rls.azimuthMin, rls.azimuthMax,
                              rls.rangeMin, rls.rangeMax);
}

void MapWidget::setDateTime(QDateTime dt)
{
    delete currentTime;
    QDate date = dt.date();
    QTime time = dt.time();
    currentTime = new DateTime(date.year(), date.month(), date.day(), time.hour(), time.minute(), time.second());
    updateGL();
}

void MapWidget::setSimpleElement(double dsR)
{
    simpleElement se;
    se.elementType = 0;
    se.arg0 = dsR;
    se.arg1 = 0;
    vSE.push_back(se);
}

void MapWidget::setSimpleElement(double dcR0, double dcR1, double dcW)
{
    simpleElement se;
    se.elementType = 1;
    se.arg0 = dcR0;
    se.arg1 = dcW;
    vSE.push_back(se);
    se.arg0 =dcR1;
}

void MapWidget::setSimpleElement(double dpH, double dpW)
{
    simpleElement se;
    se.elementType = 2;
    se.arg0 = dpH;
    se.arg1 = dpW;
    vSE.push_back(se);
}

void MapWidget::clearSimpleElements()
{
    vSE.clear();
}
