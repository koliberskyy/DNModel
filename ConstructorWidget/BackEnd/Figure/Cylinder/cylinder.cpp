#include "cylinder.h"

Cylinder::Cylinder(QWidget *parent)
{

}

GLuint Cylinder::draw(GLdouble r0, GLdouble r1, GLdouble w, GLdouble x, GLdouble y, GLdouble z)
{
    GLuint n = glGenLists(1);
    glNewList(n, GL_COMPILE);
    glBegin(GL_QUAD_STRIP);
    //qglColor(Qt::red);

        for(double i=0;i<2*dPI;i+=0.1)
        {
            glVertex3d( x-w/2,y+r0*cos(i), z+r0*sin(i));
             glVertex3d( x+w/2,y+r1*cos(i), z+r1*sin(i));
             glVertex3d( x-w/2,y+r0*cos(i+0.1), z+r0*sin(i+0.1));
             glVertex3d( x+w/2,y+r1*cos(i+0.1), z+r1*sin(i+0.1));
        }

    glEnd();

    glBegin(GL_QUAD_STRIP);
    //qglColor(Qt::red);

        for(double i=0;i<2*dPI;i+=0.1)
        {
            glVertex3d(x-w/2, y+r0*cos(i), z+r0*sin(i));
            glVertex3d( x-w/2,y-r0*cos(i), z-r0*sin(i));
        }
    glEnd();

    glBegin(GL_QUAD_STRIP);
    //qglColor(Qt::red);

        for(double i=0;i<2*dPI;i+=0.1)
        {
            glVertex3d(x+w/2,y+ r1*cos(i), z+r1*sin(i) );
            glVertex3d( x+w/2,y -r1*cos(i), z-r1*sin(i));
        }
    glEnd();


    glEndList();

    return n;

}
