#include "sphere.h"

Sphere::Sphere(QWidget *parent)
    : QGLWidget(parent)
{
}

void Sphere::initializeGL(){}
void Sphere::resizeGL(int nWidth, int nHeight){}
void Sphere::paintGL(){}

//SPHERE
GLuint Sphere::draw(GLdouble dRadius, GLdouble x, GLdouble y, GLdouble z)
{
    GLuint n = glGenLists(1);
    glNewList(n, GL_COMPILE);
    glBegin(GL_QUAD_STRIP);
    for(double t=0;t<2*dPI;t+=0.1)
        for(double i=0;i<2*dPI;i+=0.1)
        {
            glVertex3d(x+dRadius*sin(t)*cos(i),y+dRadius*sin(t)*sin(i), z+dRadius*cos(t));
            glVertex3d(x-dRadius*sin(t)*cos(i),y-dRadius*sin(t)*sin(i), z-dRadius*cos(t));
        }
    glEnd();
    glEndList();

    return n;
}
Sphere::~Sphere()
{

}
