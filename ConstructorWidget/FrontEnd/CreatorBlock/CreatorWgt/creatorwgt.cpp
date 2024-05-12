#include "creatorwgt.h"

CreatorWgt::CreatorWgt(QWidget *parent)
    : QWidget(parent)
{
    gridMain = new QGridLayout;
    comboFigure = new QComboBox;

    l1 = new QLabel;
    l2 = new QLabel;
    l3 = new QLabel;

    le1 = new QLineEdit;
    le2 = new QLineEdit;
    le3 = new QLineEdit;

    pb = new QPushButton("Добавить");

    comboFigure->addItem("Сфера");
    comboFigure->addItem("Цилиндр");
    comboFigure->addItem("Пластина");

    gridMain->addWidget(comboFigure, 0, 0, 1, 0);
    gridMain->addWidget(l1, 1, 0);
    gridMain->addWidget(l2, 2, 0);
    gridMain->addWidget(l3, 3, 0);
    gridMain->addWidget(le1, 1, 1);
    gridMain->addWidget(le2, 2, 1);
    gridMain->addWidget(le3, 3, 1);
    gridMain->addWidget(pb,4,0,1,4);

    connect(comboFigure,SIGNAL(activated(int)),this,SLOT(comboChanged(int)));
    connect(pb,SIGNAL(pressed()),this,SLOT(buttonPressed()));

    l1->setText("Радиус");
    l2->setText(" ");
    l3->setText(" ");
    le1->show();
    le2->hide();
    le3->hide();
    nFigureTrigger = SPHERE;

    QBrush br(Qt::black);
    QPalette plt = this->palette();
    plt.setBrush(QPalette::Background, br);
    this->setPalette(plt);
    l1->setStyleSheet("color: rgb(255, 255, 255)");
    l2->setStyleSheet("color: rgb(255, 255, 255)");
    l3->setStyleSheet("color: rgb(255, 255, 255)");
    this->setWindowFlags(Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint);

    setLayout(gridMain);
    show();
}
void CreatorWgt::buttonPressed()
{
    switch (nFigureTrigger) {
    case SPHERE:
        dSR=le1->text().toDouble();
        break;
    case CYLINDER:
        dCR=le1->text().toDouble();
        dCW=le3->text().toDouble();
        break;
    case PLAST:
        dPH=le1->text().toDouble();
        dPW=le2->text().toDouble();
        break;
    }
    this->hide();
    le1->setText("");
    le2->setText("");
    le3->setText("");
}

void CreatorWgt::comboChanged(int value)
{
    le1->setText("");
    le2->setText("");
    le3->setText("");

    switch (value)
    {
    case SPHERE:
        l1->setText("Радиус");
        l2->setText(" ");
        l3->setText(" ");
        le1->show();
        le2->hide();
        le3->hide();
        nFigureTrigger = SPHERE;
        break;
    case CYLINDER:
        l1->setText("Радиус");
        l2->setText(" ");
        l3->setText("Длина");
        le1->show();
        le2->hide();
        le3->show();
        nFigureTrigger = CYLINDER;
        break;
    case PLAST:
        l1->setText("Высота");
        l2->setText("Длина");
        l3->setText(" ");
        le1->show();
        le2->show();
        le3->hide();
        nFigureTrigger = PLAST;
        break;

    }
}
