#ifndef SPHERE_H
#define SPHERE_H

#include <QMainWindow>
//#include <QtOpenGL>
#include <QtOpenGL/QGLWidget>
#include <math.h>
#define dPI 3.14
class Sphere : public QGLWidget
{
    Q_OBJECT

public:
    Sphere(QWidget *parent = 0);
    GLuint draw(GLdouble R, GLdouble x, GLdouble y, GLdouble z);
    ~Sphere();
protected:
    virtual void    initializeGL    (                       );
    virtual void    resizeGL        (int nWidth, int nHeight);
    virtual void    paintGL         (                       );

};

#endif // SPHERE_H
