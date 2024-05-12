#ifndef SLIDERBLOCK_H
#define SLIDERBLOCK_H

#include <QDialog>
#include <QGridLayout>
#include <QSlider>
#include <QLabel>
//#include <QGLWidget>
#include <QWidget>

class SliderBlock : public QDialog
{
    Q_OBJECT
public:
    SliderBlock(QWidget *parent=0);

    QSlider *sliderX;
    QSlider *sliderY;
    QSlider *sliderZ;
    QSlider *sliderScale;
    QGridLayout *gridSliders;
    QLabel *labelX;
    QLabel *labelY;
    QLabel *labelZ;
    QLabel *labelScale;
protected:
    void createLabels();
    void createGrid();
    void createDialog();
    void createSliders();
};

#endif // SLIDERBLOCK_H
