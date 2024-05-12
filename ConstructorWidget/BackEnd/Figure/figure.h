#ifndef FIGURE_H
#define FIGURE_H

#include <QtOpenGL/QGLWidget>
#include"Sphere/sphere.h"
#include"Cylinder/cylinder.h"
#include"Plast/plast.h"

class Figure : public QGLWidget
{
public:
    Figure();
    Sphere *sphere;
    Cylinder *cylinder;
    Plast *plast;
protected:
    virtual void    initializeGL    (                       ){}
    virtual void    resizeGL        (){}
    virtual void    paintGL         (                       ){}


};

#endif // FIGURE_H
