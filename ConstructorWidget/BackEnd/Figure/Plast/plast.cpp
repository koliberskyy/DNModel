#include "plast.h"

Plast::Plast(QWidget *parent)
{

}

GLuint Plast::draw(GLdouble h, GLdouble w, GLdouble x, GLdouble y, GLdouble z)
{
    GLuint n = glGenLists(1);

    glNewList(n, GL_COMPILE);
    glBegin(GL_QUADS);
    //qglColor(Qt::green);
    glVertex3d(x, y-h/2, z);
    glVertex3d(x, y+h/2, z);
    glVertex3d(w+x, y+h/2, z);
    glVertex3d(w+x, y-h/2, z);
    glEnd();


    glEndList();

    return n;
}
