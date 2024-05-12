#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include"FrontEnd/CreatorBlock/creatorblock.h"
#include "FrontEnd/SliderBlock/sliderblock.h"
#include"BackEnd/backend.h"
#include <QtOpenGL/QGLWidget>
#include <QMouseEvent>

//sliderXchanged->sliderYchanged
class MainWidget : public QGLWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = 0);
    ~MainWidget();
protected:
    //OGL virtuals
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();
    //EVENTS
    void moveEvent(QMoveEvent *);
    void closeEvent(QCloseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mousePressEvent(QMouseEvent *e);
    void resizeEvent(QResizeEvent *e);
    void showEvent(QShowEvent *e);
    //Blocks
    void createBlockSliders();
    void createBlockCreator();
    void createCreatorWgt();
    void createConnections();
    //draws
    void glDrawScene();
    void glDrawAxis();
    void glDrawFigure(int i);

public:
    CreatorBlock *creatorBlock;
    CreatorWgt *creatorWgt;
protected:
    SliderBlock *sliderBlock;
    BackEnd *backEnd;
    DataBase *data;
    int id;
    int idMf;
    std::vector<GLuint> vec;
    GLdouble xRot, yRot, scale;
    QPoint pe;
signals:
    void sphereCreated(double radius_tmp);
    void cylinderCreated(double radius0_tmp, double radius1_tmp, double width_tmp);
    void plastCreated(double height_tmp, double width_tmp);
public slots:
    void buttonAddPressed();
    void buttonCreatePressed();
    void sliderXChanged(int mf);
    void sliderYChanged(int mf);
    void sliderZChanged(int mf);
    void sliderScaleChanged(int mf);
    void comboChanged(int mf);
    void deleteButtonPressed();
};

#endif // MAINWIDGET_H
