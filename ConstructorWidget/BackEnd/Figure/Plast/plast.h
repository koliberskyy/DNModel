#ifndef PLAST_H
#define PLAST_H

#include <QMainWindow>
//#include <QtOpenGL>
#include <QtOpenGL/QGLWidget>
#define dPI 3.14

class Plast : public QGLWidget
{
public:
    Plast(QWidget *parent = 0);
    GLuint draw(GLdouble h, GLdouble w, GLdouble x, GLdouble y, GLdouble z);
protected:
    virtual void    initializeGL    (                       ){}
    virtual void    resizeGL        (){}
    virtual void    paintGL         (                       ){}
};

#endif // PLAST_H
