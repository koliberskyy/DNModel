#include "database.h"

DataBase::DataBase(int &tmp_id)
{
    id = tmp_id;         //уникальный идентификатор объекта
    g0 = 1;    //размеры объекта
    g1 = 1;
    g2 = 1;
    x = 0;     //положение объекта в пространстве
    y = 0;
    z = 0;
}
DataBase::DataBase()
{
    g0 = 1;    //размеры объекта
    g1 = 1;
    g2 = 1;
    x = 0;     //положение объекта в пространстве
    y = 0;
    z = 0;
}
