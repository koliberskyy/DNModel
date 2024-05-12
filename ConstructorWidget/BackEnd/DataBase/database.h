#ifndef DATABASE_H
#define DATABASE_H


#include <QtOpenGL/QGLWidget>
//#include <QtOpenGL>
#define SPHERE 0
#define CYLINDER 1
#define PLAST 2
#include "../Figure/figure.h"
class DataBase
{
public:
    DataBase(int &tmp_id);
    DataBase();
    int object; // SPHERE/CYLINDER/PLAST
    int id;         //уникальный идентификатор объекта
    GLdouble g0;    //размеры объекта
    GLdouble g1;
    GLdouble g2;
    GLdouble x;     //положение объекта в пространстве
    GLdouble y;
    GLdouble z;
    Sphere *sphere;




    void addData(GLdouble r)
    {
        g0=r;
        object=SPHERE;

    }
    void addData(GLdouble r0, GLdouble r1, GLdouble w)
    {

        g0=r0;
        g1=r1;
        g2=w;
        object=CYLINDER;
    }
    void addData(GLdouble h, GLdouble w)
    {

        g0=h;
        g1=w;
        object=PLAST;

    }


};

#endif // DATABASE_H
