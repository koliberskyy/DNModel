#include "sliderblock.h"

SliderBlock::SliderBlock(QWidget *parent)
    : QDialog(parent)
{
    createSliders();
    createLabels();
    createGrid();
    createDialog();
    this->show();
    sliderScale->setValue(100);

}

void SliderBlock::createLabels()
{
    //LABELES
    labelX = new QLabel(tr("X"));
    labelY = new QLabel(tr("Y"));
    labelZ = new QLabel(tr("Z"));
    labelScale = new QLabel(tr("Масштаб"));
    labelX->setStyleSheet("color: rgb(255, 255, 255)");
    labelY->setStyleSheet("color: rgb(255, 255, 255)");
    labelZ->setStyleSheet("color: rgb(255, 255, 255)");
    labelScale->setStyleSheet("color: rgb(255, 255, 255)");
}

void SliderBlock::createGrid()
{
    gridSliders = new QGridLayout;
    gridSliders->addWidget(sliderX,0,0);
    gridSliders->addWidget(sliderY,1,0);
    gridSliders->addWidget(sliderZ,2,0);
    gridSliders->addWidget(sliderScale,3,0);
    gridSliders->addWidget(labelX,0,1);
    gridSliders->addWidget(labelY,1,1);
    gridSliders->addWidget(labelZ,2,1);
    gridSliders->addWidget(labelScale,3,1);
}

void SliderBlock::createDialog()
{

    this->setWindowFlags(Qt::CustomizeWindowHint | Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    setLayout(gridSliders);
    QBrush br(Qt::black);
    QPalette plt = this->palette();
    plt.setBrush(QPalette::Background, br);
    this->setPalette(plt);
}
void SliderBlock::createSliders()
{
    //SLIDERS
    sliderX = new QSlider(Qt::Horizontal);
    sliderY = new QSlider(Qt::Horizontal);
    sliderZ = new QSlider(Qt::Horizontal);
    sliderScale = new QSlider(Qt::Horizontal);
    sliderX->setRange(-15,15);
    sliderY->setRange(-15,15);
    sliderZ->setRange(-15,15);
    sliderScale->setRange(50,250);
    sliderX->setSingleStep(0.5);
    sliderY->setSingleStep(0.5);
    sliderZ->setSingleStep(0.5);
    sliderScale->setSingleStep(10);
    sliderX->setStyleSheet("QSlider::handle:horizontal{background-color:red;}");
    sliderY->setStyleSheet("QSlider::handle:horizontal{background-color:green;}");
    sliderZ->setStyleSheet("QSlider::handle:horizontal{background-color:blue;}");
    sliderScale->setStyleSheet("QSlider::handle:horizontal{background-color:white;}");
}

