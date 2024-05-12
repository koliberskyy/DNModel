#include "backend.h"

BackEnd::BackEnd()
{
    idTrigger=0;
    idLast=0;
}

GLuint BackEnd::create(DataBase *in)
{
    switch (in->object) {
    case SPHERE:
        return figure.sphere->draw(in->g0, in->x, in->y, in->z);
        break;
    case CYLINDER:
        return figure.cylinder->draw(in->g0, in->g1, in->g2, in->x, in->y, in->z);
        break;
    case PLAST:
        return figure.plast->draw(in->g0, in->g1, in->x, in->y, in->z);
        break;
    }
}
void BackEnd::move(int id, GLuint x, GLuint y, GLuint z)
{
    iData[id].x=x;
    iData[id].y=y;
    iData[id].z=z;
}
void BackEnd::resize(int id, GLuint r)
{
    iData[id].g0=r;
}
void BackEnd::resize(int id, GLuint r0, GLuint r1, GLuint w)
{
    iData[id].g0=r0;
    iData[id].g1=r1;
    iData[id].g2=w;
}
void BackEnd::resize(int id, GLuint h, GLuint w)
{
    iData[id].g0=h;
    iData[id].g1=w;
}
void BackEnd::set(int id, GLuint r, GLuint x, GLuint y, GLuint z)
{
    resize(id,r);
    move(id,x,y,z);
}
void BackEnd::set(int id, GLuint r0, GLuint r1, GLuint w, GLuint x, GLuint y, GLuint z)
{
    resize(id,r0, r1, w);
    move(id,x,y,z);
}
void BackEnd::set(int id, GLuint h, GLuint w, GLuint x, GLuint y, GLuint z)
{
    resize(id, h, w);
    move(id,x,y,z);
}

void BackEnd::addData(GLdouble r)
{
    idLast++;
    DataBase tmp;
    tmp.g0=r;
    tmp.object=SPHERE;
    tmp.id=idLast;
    iData.push_back(tmp);
}
void BackEnd::addData(GLdouble r0, GLdouble r1, GLdouble w)
{
    idLast++;
    DataBase tmp;
    tmp.g0=r0;
    tmp.g1=r1;
    tmp.g2=w;
    tmp.object=CYLINDER;
    tmp.id=idLast;
    iData.push_back(tmp);
}
void BackEnd::addData(GLdouble h, GLdouble w)
{
    idLast++;
    DataBase tmp;
    tmp.g0=h;
    tmp.g1=w;
    tmp.object=PLAST;
    tmp.id=idLast;
    iData.push_back(tmp);
}
