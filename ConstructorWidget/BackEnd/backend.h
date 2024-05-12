#ifndef BACKEND_H
#define BACKEND_H


#include <QtOpenGL/QGLWidget>
//#include <QtOpenGL>
#include "DataBase/database.h"
#include "Figure/figure.h"
#include "vector"


class BackEnd : public QGLWidget
{
public:
    BackEnd();
    std::vector<GLuint> oData; //данные фигур для openGL
    std::vector<DataBase> iData; //геометрические данные о фигурах
    DataBase *mass;
    int idTrigger; //хранит текущий id
    int idLast; // последний использованный +1
    Figure figure;
    GLuint create(DataBase *in);//берет данные из структуры и создает объект типa gluint
    void move(int id, GLuint x, GLuint y, GLuint z);
    void resize(int id, GLuint r);
    void resize(int id, GLuint r0, GLuint r1, GLuint w);
    void resize(int id, GLuint h, GLuint w);
    void set(int id, GLuint r, GLuint x, GLuint y, GLuint z);
    void set(int id, GLuint r0, GLuint r1, GLuint w, GLuint x, GLuint y, GLuint z);
    void set(int id, GLuint h, GLuint w, GLuint x, GLuint y, GLuint z);
    void addData(GLdouble r);
    void addData(GLdouble r0, GLdouble r1, GLdouble w);
    void addData(GLdouble h, GLdouble w);
};


#endif // BACKEND_H
