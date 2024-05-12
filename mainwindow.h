#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMetaMethod>
#include "MapWidget2/mapwidget.h"
#include "ConstructorWidget/mainwidget.h"
#include <QGridLayout>
#include <QDialog>
#include <QWidget>
#include "MapControlUnit/mapcontrolunit.h"
#include "Timer/timer.h"
#include <QMenuBar>
#include <QMenu>
#include <QThread>
#include <QDateTimeEdit>
#include <QTextBrowser>
#include <QString>
#include <vector>
#include "graphsscene.h"
//добавить градацию осям координат
// сделать перемещение графика мышкой
// сделать нормальный зум
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void startFlight();
    void stopFlight();
    void clearMap();
    void writeDateTimeIn(DateTime dT);
    void writeDateTimeOut(DateTime dT);
    void clearDateTimeIn();
    void clearDateTimeOut();
private:
    //central widget
    QWidget         *central;
    QGridLayout     *mainGrid;

    //main units
    MapWidget       *mapWidget;
    MainWidget      *constructorWidget;
    MapControlUnit  *mapControlUnit;

    //MENUBAR
    QMenuBar        *mainMenuBar;
    QMenu           *menu0;

    //currentTime
    QGridLayout     *timeGrid;
    QDateTimeEdit   *dateTimeEdit;

    //time in/time out
    QTextBrowser *textBrowser;
    QTextBrowser *textBrowser1;

    //Вектор хранящий времена входа/выхода
    std::vector <DateTime> vInsideTime;
    std::vector <DateTime> vOutsideTime;

    //Зона рисования графиков ЭПР
    GraphsScene *graphArea;



    vector<double> vESA;
    vector<double> vAngle;

    ///INTERFACE
    void createInterface();
    void createTimer();
    void createMenuBar();
    void createCurrentTimeUnit();
    void createConnections();
    //events
    void closeEvent(QCloseEvent *e);

    //Timer
    QThread     thr;
    Timer       *timer;
};

#endif // MAINWINDOW_H
