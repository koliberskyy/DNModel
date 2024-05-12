#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    createInterface();
    createTimer();
    createConnections();
}

MainWindow::~MainWindow()
{
    thr.quit();
    thr.wait();
    delete timer;
}


void MainWindow::createInterface()
{
    mainGrid            = new QGridLayout;
    mapWidget           = new MapWidget;
    constructorWidget   = new MainWidget;
    central             = new QWidget;
    mapControlUnit      = new MapControlUnit;
    timer               = new Timer;
    textBrowser         = new QTextBrowser;
    textBrowser1        = new QTextBrowser;
    graphArea           = new GraphsScene;

    //MENUBAR
    createMenuBar();
    setMenuBar(mainMenuBar);

    //Time Layout
    createCurrentTimeUnit();
    mapControlUnit->mainGrid->addLayout(timeGrid, 0, 0, 1, 1);

    //SETFIXEDSIZE
    mainGrid->addWidget(constructorWidget,  0, 1);
    mainGrid->addWidget(mapWidget,          0, 0);
    mainGrid->addWidget(mapControlUnit,     1, 1);
    mainGrid->addLayout(timeGrid,           1, 2);
    //mainGrid->addWidget(textBrowser,        1, 3);
    //mainGrid->addWidget(textBrowser1,       1, 4);
    mainGrid->addWidget(graphArea,          1, 0);

    graphArea->setFixedSize(500,250);
    mapWidget->setFixedSize(800,400);
    constructorWidget->setFixedSize(400,400);
    central->setLayout(mainGrid);
    setCentralWidget(central);



    //Демонстрационный режим
    Tle tle = Tle("UK-DMC 2                ",
                      "1 35683U 09041C   12305.23158813  .00000484  00000-0  89219-4 0  5863",
                      "2 35683  80.0000 185.3682 0001499 100.5295 259.6088 14.69819587172294");
    RLS rls(34,45,1,90,0,360,120,3600);
    mapWidget->drawTrase(tle,tle.Epoch());
    mapWidget->drawRLS(rls);
}


void MainWindow::closeEvent(QCloseEvent *e)
{
    e->accept();
    mapWidget->close();
    delete mapWidget;
    constructorWidget->close();
    delete constructorWidget;
    delete mapControlUnit;
    delete central;
}


void MainWindow::createTimer()
{
    timer->moveToThread(&thr);
    thr.start();
    connect(mapControlUnit, SIGNAL(buttonStartPressed()),
            timer,          SLOT(run()));
    connect(mapControlUnit, SIGNAL(buttonStartPressed()),
            this,           SLOT(startFlight()));
    connect(mapControlUnit, SIGNAL(buttonStopPressed()),
            this,           SLOT(stopFlight()));
    connect(mapControlUnit, SIGNAL(buttonSbrosPressed()),
            this,           SLOT(clearMap()));
}


void MainWindow::createConnections()
{
    connect(dateTimeEdit,   SIGNAL(dateTimeChanged(QDateTime)),
            this,           SLOT(clearDateTimeIn()));
    connect(mapWidget,      SIGNAL(inside(DateTime)),
            this,           SLOT(writeDateTimeIn(DateTime)));
    connect(dateTimeEdit,   SIGNAL(dateTimeChanged(QDateTime)),
            this,           SLOT(clearDateTimeOut()));
    connect(mapWidget,      SIGNAL(outside(DateTime)),
            this,           SLOT(writeDateTimeOut(DateTime)));
    connect(mapWidget,      SIGNAL(ESACalculated(vector<double>&, vector<double>&)),
            graphArea,      SLOT(drawGraph(vector<double>&, vector<double>&)));
    connect(constructorWidget, SIGNAL(sphereCreated(double)),
            mapWidget,          SLOT(setSimpleElement(double)));
    connect(constructorWidget, SIGNAL(cylinderCreated(double,double,double)),
            mapWidget,          SLOT(setSimpleElement(double,double,double)));
    connect(constructorWidget, SIGNAL(plastCreated(double,double)),
            mapWidget,          SLOT(setSimpleElement(double, double)));
    connect(constructorWidget->creatorBlock->buttonDelete, SIGNAL(pressed()),
            mapWidget,          SLOT(clearSimpleElements()));
}


void MainWindow::startFlight()
{
    connect(timer,          SIGNAL(currDate(QDate)),
            dateTimeEdit,   SLOT(setDate(QDate)));
    connect(timer,          SIGNAL(currTime(QTime)),
            dateTimeEdit,   SLOT(setTime(QTime)));
}


void MainWindow::stopFlight()
{
    //disconnect(dateTimeEdit, SIGNAL(dateTimeChanged(QDateTime)), mapWidget, SLOT(setDateTime(QDateTime)));
    disconnect(timer, SIGNAL(currDate(QDate)),dateTimeEdit, SLOT(setDate(QDate)));
    disconnect(timer, SIGNAL(currTime(QTime)),dateTimeEdit, SLOT(setTime(QTime)));
}


void MainWindow::clearMap()
{
    mapControlUnit->doubleSpinBox->setValue(0);
    mapWidget->setDateTime(mapWidget->getEpoch());
    vInsideTime.clear();
    textBrowser->clear();
}


void MainWindow::writeDateTimeIn(DateTime dT)
{
    bool trigger(1);
    for(unsigned int i = 0; i < vInsideTime.size(); i++)
    {
        if(vInsideTime[i] == dT)
        {
            trigger = 0;
            break;
        }
    }
    if(trigger == 1)
        vInsideTime.push_back(dT);
    textBrowser->clear();
    for(unsigned int i = 0; i < vInsideTime.size(); i++)
    {
       textBrowser->append(QString("Вход:") + QString(vInsideTime[i].ToString().c_str()));
    }
}

void MainWindow::writeDateTimeOut(DateTime dT)
{
    bool trigger(1);
    for(unsigned int i = 0; i < vOutsideTime.size(); i++)
    {
        if(vOutsideTime[i] == dT)
        {
            trigger = 0;
            break;
        }
    }
    if(trigger == 1)
        vOutsideTime.push_back(dT);
    textBrowser1->clear();
    for(unsigned int i = 0; i < vOutsideTime.size(); i++)
    {
       textBrowser1->append(QString("Выход:") + QString(vOutsideTime[i].ToString().c_str()));
    }
}


void MainWindow::clearDateTimeIn()
{
    vInsideTime.clear();
}


void MainWindow::clearDateTimeOut()
{
    vOutsideTime.clear();
}

void MainWindow::createMenuBar()
{
    mainMenuBar         = new QMenuBar;
    // menu file
    menu0               = new QMenu("Файл");
    QAction *actionExit = new QAction("Выход", menu0);
    connect(actionExit,     SIGNAL(triggered(bool)),
            this,           SLOT(close()));

    menu0->addAction(actionExit);
    mainMenuBar->addMenu(menu0);
}

void MainWindow::createCurrentTimeUnit()
{
    timeGrid = new QGridLayout;
    dateTimeEdit = new QDateTimeEdit;
    timeGrid->addWidget(dateTimeEdit);
    dateTimeEdit->setDisplayFormat("hh.mm.ss dd.MM.yyyy");
    connect(dateTimeEdit, SIGNAL(dateTimeChanged(QDateTime)), mapWidget, SLOT(setDateTime(QDateTime)));
}








