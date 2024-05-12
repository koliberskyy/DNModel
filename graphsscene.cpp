#include "graphsscene.h"

GraphsScene::GraphsScene(QWidget *parent)
    : QGLWidget(parent)
{
     xMin =-10;
     xMax =10000;
     yMin =-10;
     yMax =5000;
     scale = 1;
     mouseX = 0;
     mouseY=0;
     vESA.clear();
     vAngle.clear();
}


void GraphsScene::initializeGL()
{
    qglClearColor(Qt::white);
    gluOrtho2D(xMin, xMax, yMin, yMax);
}


void GraphsScene::resizeGL(int w, int h)
{
    glViewport(50,50,w,h);
}


void GraphsScene::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glScaled(scale, scale, 1);
    glTranslated(mouseX/10,0, 0);
    glTranslated(0,-mouseY/10, 0);
    drawGraph();
    drawAxis();
}

void GraphsScene::drawAxis()
{
    qglColor(Qt::black);
    glLineWidth(1.5);
    glBegin(GL_LINES);
        glVertex2d(-1,0);
        glVertex2d(vAngle.size(),0);
    glEnd();
    glBegin(GL_LINES);
        glVertex2d(0, -1);
        glVertex2d(0, vESA.size());
    glEnd();
    glBegin(GL_POINTS);
    glPointSize(5);
    for(int i=0; i<vAngle.size();i+=5)
    {
        glVertex2d(i,0);
    }
    glEnd();

    for(int i=0; i<vAngle.size();i+=10)
    {
        stringstream ss;
        ss << i;
        string s=ss.str();
        for(int j=0; j<s.size(); j++)
        {
            glRasterPos2d(i+j*2,1);
            //glutBitmapCharacter(GLUT_BITMAP_8_BY_13, s[j]);
        }
     }

    for(int i=0; i<vESA.size();i+=5)
    {
        glVertex2d(0,i);
    }
    glEnd();

    for(int i=0; i<vESA.size();i+=10)
    {
        stringstream ss;
        ss << i;
        string s=ss.str();
        for(int j=0; j<s.size(); j++)
        {
            glRasterPos2d(j*2,i);
            //glutBitmapCharacter(GLUT_BITMAP_8_BY_13, s[j]);
        }
     }
}

void GraphsScene::wheelEvent(QWheelEvent *eve)
{
    if(eve->delta()>0)
        scale*=1.05;
    else
    if(eve->delta()<0)
        scale/=1.05;
    updateGL();
    if(eve->delta()>0)
        scale/=1.05;
    else
    if(eve->delta()<0)
        scale*=1.05;
}

void GraphsScene::mousePressEvent(QMouseEvent *event)
{
    pe=event->pos();
}

void GraphsScene::mouseMoveEvent(QMouseEvent *event)
{
    mouseX+= event->x() - pe.x();
    mouseY+= event->y() - pe.y();
    updateGL();
    mouseX-= event->x() - pe.x();
    mouseY-= event->y() - pe.y();
}

void GraphsScene::mouseReleaseEvent(QMouseEvent *event)
{
}



void GraphsScene::resizeMF()
{
    xMax = 100;
    yMax = 100;
    updateGL();
}

void GraphsScene::drawPoint(double angle, double ESA)
{
    vAngle.push_back(angle);
    vESA.push_back(ESA);
    updateGL();
}

void GraphsScene::drawGraph(vector<double> &vESA_tmp, vector<double> &vAngle_tmp)
{
    glClear(GL_CLEAR);
    vESA=vESA_tmp;
    vAngle=vAngle_tmp;
    updateGL();
}

void GraphsScene::drawGraph()
{
    qglColor(Qt::red);
    glPointSize(3);
    glBegin(GL_POINTS);
    for(int i=0; i<vESA.size(); i++)
    {

        glVertex2d(vAngle[i], vESA[i]);

    }
    glEnd();

}
