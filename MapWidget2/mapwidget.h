#ifndef MAPWIDGET_H
#define MAPWIDGET_H

#include <QWidget>
#include <QtOpenGL/QGLWidget>
#include"../libsgp4/CoordGeodetic.h"
#include"../libsgp4/Vector.h"
#include"../libsgp4/CoordTopocentric.h"
#include"../libsgp4/Observer.h"
#include"../libsgp4/SGP4.h"
#include"../libsgp4/Eci.h"
#include"../libsgp4/Tle.h"
#include"rls.h"
#include <math.h>
#include <QDateTime>
#include <vector>
using namespace std;
struct simpleElement
{
    int elementType;// 0 - сфера, 1 - цилиндр, 2 - пластина
    double arg0;//радиус/радиус/высота
    double arg1;//000000/длина /ширина
};
class MapWidget : public QGLWidget
{
    Q_OBJECT

public:
    MapWidget(QWidget *parent = 0);
    ~MapWidget();
    //Возвращает true если точка "eci" в системе Eci попадает в зону обзора "rls"
    bool isVisibleDegreesIn(Eci eci, RLS rls);
    //Рисует трассу КА путём изменения значения поля "tle" и значения времени
    //положение КА "tle" в момент времени "currTime"
    void drawTrase(Tle tle, DateTime currTime);
    //Рисует рлс путём изменения значения поля "rls"
    void drawRLS(RLS rls);
    // Возвращает эпоху КА
    QDateTime getEpoch();
public slots:
    //устанавливает время относительно которого происходит прогноз
    void setDateTime(QDateTime dt);
    // записывает геометрию куска в структуру
    void setSimpleElement(double dsR);
    void setSimpleElement(double dcR0, double dcR1, double dcW);
    void setSimpleElement(double dpH, double dpW);
    void clearSimpleElements();
signals:
    //Сигнализирует попадание КА в зону обзора
    void inside (DateTime dT);
    //Сигнализирует выход КА из зоны обзора
    void outside(DateTime dT);
    //ЭПР и углы сосчитаны
    void ESACalculated(vector<double> &vESA_tmp,
                       vector<double> &vAngle_tmp);

private:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();
    //При изменении этих параметров изменяетя рисуемое изображение
    Tle         *tle;
    RLS         *rls;
    DateTime    *currentTime;

    ///всё что касается расчета ЭПР
    /// 00000000000000000000000000000000
    std::vector<double>     vESA;       //содержит все значения ЭПР
    std::vector<double>     vAngle;     //значения углов локации
    std::vector<simpleElement> vSE;     //все фигуры
    const double            PI;         //Пи
    double                  waveLength; //длина волны
    //возвращает угол локации в градусах
    double locaAngle(Eci ka_tmp,                double latitude_tmp,
                     double longtitude_tmp,     double altitude_tmp);
    //возвращает ЭПР сферы
    double ESA(double radius);
    //возвращает ЭПР цилиндра от угла локации(Градусы)
    double ESA(double radius0, double radius1, double width, double locationAngle);
    //возвращает ЭПР пластины от угла локации(Градусы)
    double ESA(double height, double width, double locationAngle);
    //суммарная ЭПР
    void calculateESA(Eci eci_tmp,              double latitude_tmp,
                      double longtitude_tmp,    double altitude_tmp);

    //Фоновое изображение
    void genTextures();
    void drawBackground();

    //метод рисования основного премитива
    void drawPoint2d(double x, double y);

    //Рисование зоны обзора
    void drawViewZoneDegreesIn(RLS rls);
    void drawViewZoneDegreesIn(double latitude,      double longtitude,
                              double elevationMin,  double elevationMax,
                              double azimuthMin,    double azimuthMax,
                              double rangeMin,      double rangeMax);
    void drawViewZoneRadianIn(double latitude,      double longtitude,
                              double elevationMin,  double elevationMax,
                              double azimuthMin,    double azimuthMax,
                              double rangeMin,      double rangeMax);
    void drawViewZonePointRadianIn(double latitude, double longtitude,
                                   double elevation, double azimuth,
                                   double range);

    //Рисование трассы полёта
    void drawTrace(Tle tle, RLS rls, DateTime dateTime);

    //виден/невиден
    bool isVisibleDegreesIn(Eci eci, double latitude,      double longtitude,
                                     double elevationMin,  double elevationMax,
                                     double azimuthMin,    double azimuthMax,
                                     double rangeMin,      double rangeMax);
};

#endif // MAPWIDGET_H
