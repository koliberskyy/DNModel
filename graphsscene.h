#ifndef GRAPHSSCENE_H
#define GRAPHSSCENE_H

#include <QObject>
#include <QtOpenGL/QGLWidget>
#include <vector>
#include <GL/glu.h>
//#include <GL/glut.h>
#include <QWheelEvent>
#include <stdlib.h>
#include <stdio.h>
#include <QString>
#include <sstream>
//#include <GL/freeglut.h>
#include <QKeyEvent>
using namespace std;
class GraphsScene : public QGLWidget
{
    Q_OBJECT
public:
    GraphsScene(QWidget *parent = 0);

private:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();
    double xMin;
    double xMax;
    double yMin;
    double yMax;
    double scale;
    int mouseX;
    int mouseY;
    void drawAxis();
    void drawGraph();
    void wheelEvent(QWheelEvent *eve);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    QPoint pe;
    vector<double> vAngle;
    vector<double> vESA;
public slots:
    void resizeMF();
    void drawPoint(double angle, double ESA);
    void drawGraph(vector<double> &vESA_tmp, vector<double> &vAngle_tmp);
};

#endif // GRAPHSSCENE_H
