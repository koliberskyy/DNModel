#include "mapcontrolunit.h"

MapControlUnit::MapControlUnit(QWidget *parent) : QWidget(parent)
{
    createWidget();
    createConnects();
}


void MapControlUnit::createWidget()
{
    bStart          = new QPushButton("Старт");
    currentTime     = new QLabel("ЭПР");
    mainGrid        = new QGridLayout;
    timeEdit        = new QSpinBox;
    doubleSpinBox   = new QDoubleSpinBox;

    doubleSpinBox->setRange(0.0, 100000.0);
    mainGrid->addWidget(bStart,     1, 0, 1, 2);
    //mainGrid->addWidget(currentTime,0, 0, 1, 1);
    setLayout(mainGrid);
}


void MapControlUnit::start()
{
    bStop = new QPushButton("Стоп");
    connect(bStop,      SIGNAL(pressed()),
            this,       SLOT(stop()));
    mainGrid->replaceWidget(bStart, bStop);
    delete bStart;
    emit buttonStartPressed();
}


void MapControlUnit::stop()
{

    bContinue = new QPushButton("Сброс");
    connect(bContinue,  SIGNAL(pressed()),
            this,       SLOT(sbros()));
    mainGrid->replaceWidget(bStop, bContinue);
    delete bStop;
    emit buttonStopPressed();
}


void MapControlUnit::sbros()
{
    bStart = new QPushButton("Старт");
    connect(bStart,     SIGNAL(pressed()),
            this,       SLOT(start()));
    mainGrid->replaceWidget(bContinue, bStart);
    delete bContinue;
    emit buttonSbrosPressed();
}

void MapControlUnit::createConnects()
{
    connect(bStart,     SIGNAL(pressed()),
            this,       SLOT(start()));

//    connect(bStop,      SIGNAL(pressed()),
//            this,       SLOT(stop()));


}
