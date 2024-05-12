#include "mainwindow.h"
#include <QApplication>
#include <GL/glu.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
   // w.setWindowFlags(Qt::WindowStaysOnBottomHint);
    w.showMaximized();
   // w.showFullScreen();
   // glutInit(&argc, argv);
    return a.exec();
}
