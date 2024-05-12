#ifndef CYLINDER_H
#define CYLINDER_H

#include <QMainWindow>
//#include <QtOpenGL>
#include <QtOpenGL/QGL>
#include <QtOpenGL/QGLWidget>
#include <math.h>
#define dPI 3.14

class Cylinder : public QGLWidget
{
public:
    Cylinder(QWidget *parent = 0);
    GLuint draw(GLdouble r0, GLdouble r1, GLdouble w, GLdouble x, GLdouble y, GLdouble z);
protected:
    virtual void    initializeGL    (                       ){}
    virtual void    resizeGL        (){}
    virtual void    paintGL         (                       ){}
};

#endif // CYLINDER_H
