#include "mapwidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MapWidget w;
    w.show();

    return a.exec();
}
