#include "mainwidget.h"

MainWidget::MainWidget(QWidget *parent)
    : QGLWidget(parent)
{
    createBlockSliders();
    createBlockCreator();
    createCreatorWgt();
    createConnections();
    backEnd = new BackEnd;
    data = new DataBase[10];
    id=0;
    xRot=0;
    yRot=0;
    idMf=0;
    scale=100;
}

MainWidget::~MainWidget()
{

}

void MainWidget::initializeGL()
{
    qglClearColor(Qt::black);
    glOrtho(-50,50,-50,50,50,50);
    glShadeModel(GL_FLAT);
}

void MainWidget::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-15,15,-15,15,15,-15);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

}
void MainWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRotated(xRot/16,1,0,0);
    glRotated(yRot/16,0,1,0);
    glScaled(scale/100, scale/100, scale/100);
    glDrawScene();


}
//********CREATES
void MainWidget::createBlockSliders()
{
    sliderBlock = new SliderBlock;
}

void MainWidget::createBlockCreator()
{
    creatorBlock = new CreatorBlock;
}
void MainWidget::createCreatorWgt()
{
    creatorWgt = new CreatorWgt;
    creatorWgt->hide();
}
void MainWidget::createConnections()
{
    connect(creatorBlock->buttonAdd,
            SIGNAL(pressed()),
            this,
            SLOT(buttonAddPressed()));

    connect(creatorWgt->pb,
            SIGNAL(pressed()),
            this,
            SLOT(buttonCreatePressed()));

    connect(sliderBlock->sliderX,
            SIGNAL(sliderMoved(int)),
            this,
            SLOT(sliderXChanged(int)));
    connect(sliderBlock->sliderY,
            SIGNAL(sliderMoved(int)),
            this,
            SLOT(sliderYChanged(int)));
    connect(sliderBlock->sliderZ,
            SIGNAL(sliderMoved(int)),
            this,
            SLOT(sliderZChanged(int)));
    connect(sliderBlock->sliderScale,
            SIGNAL(sliderMoved(int)),
            this,
            SLOT(sliderScaleChanged(int)));

    connect(creatorBlock->comboBox,
            SIGNAL(currentIndexChanged(int)),
            this,
            SLOT(comboChanged(int)));
    connect(creatorBlock->buttonDelete,
            SIGNAL(pressed()),
            this,
            SLOT(deleteButtonPressed()));

}

//**********EVENTS
void MainWidget::moveEvent(QMoveEvent *)
{
    QPoint p = this->mapToGlobal(QPoint(0, 0));
    int x = p.x();
    int y = p.y();
    sliderBlock->move(x,y);
    creatorBlock->move(x+this->width()-creatorBlock->width(),y);
    creatorWgt->move(x+this->width()-creatorWgt->width(),y);
}

void MainWidget::closeEvent(QCloseEvent *e)
{
    e->accept();
    delete sliderBlock;
    delete creatorBlock;
    delete creatorWgt;
}
void MainWidget::mouseMoveEvent(QMouseEvent *event)
{
    yRot+= event->x() - pe.x();
    xRot+= event->y() - pe.y();
    updateGL();
//    yRot-= event->x() - pe.x();
//    xRot-= event->y() - pe.y();
}
void MainWidget::mousePressEvent(QMouseEvent *event)
{
    pe=event->pos();
}
void MainWidget::resizeEvent(QResizeEvent *e)
{
    resizeGL(e->size().width(),e->size().height());
    QPoint p = this->mapToGlobal(QPoint(0, 0));
    int x = p.x();
    int y = p.y();
    sliderBlock->move(x,y);
    creatorBlock->move(x+this->width()-creatorBlock->width(),y);
    creatorWgt->move(x+this->width()-creatorWgt->width(),y);
}
void MainWidget::showEvent(QShowEvent *e)
{
    e->accept();
    //creatorBlock->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
}
//*************SLOTS
void MainWidget::buttonAddPressed()
{
    creatorWgt->show();
}
void MainWidget::buttonCreatePressed()
{
    switch (creatorWgt->nFigureTrigger)
    {
    case SPHERE:
        data[id].addData(creatorWgt->dSR);
        creatorBlock->comboBox->addItem("Сфера");
        emit sphereCreated(creatorWgt->dSR);
        break;
    case CYLINDER:
        data[id].addData(creatorWgt->dCR,creatorWgt->dCR,creatorWgt->dCW);
        creatorBlock->comboBox->addItem("Цилиндр");
        emit cylinderCreated(creatorWgt->dCR, creatorWgt->dCR, creatorWgt->dCW);
        break;
    case PLAST:
        data[id].addData(creatorWgt->dPH,creatorWgt->dPW);
        creatorBlock->comboBox->addItem("Пластина");
        emit plastCreated(creatorWgt->dPH, creatorWgt->dPW);
        break;
    }
    id++;
    updateGL();
}
void MainWidget::sliderXChanged(int mf)
{
    data[idMf].x=mf;
    updateGL();
}
void MainWidget::sliderYChanged(int mf)
{
    data[idMf].y=mf;
    updateGL();
}
void MainWidget::sliderZChanged(int mf)
{
    data[idMf].z=mf;
    updateGL();
}
void MainWidget::sliderScaleChanged(int mf)
{
    scale=mf;
    updateGL();
}
void MainWidget::comboChanged(int mf)
{
    idMf=mf;
    int x,y,z;
    x=data[idMf].x;
    y=data[idMf].y;
    z=data[idMf].z;
    sliderBlock->sliderX->setValue(x);
    sliderBlock->sliderY->setValue(y);
    sliderBlock->sliderZ->setValue(z);
}

void MainWidget::glDrawAxis()
{
    glLineWidth(1.0);
    glBegin(GL_LINES);
        glColor3d(1,0,0);
        glVertex3d(-150,0,0);
        glVertex3d(150,0,0);

        glColor3d(0,1,0);
        glVertex3d(0,150,0);
        glVertex3d(0,-150,0);

        glColor3d(0, 0, 1);
        glVertex3d(0, 0, 150);
        glVertex3d(0, 0, -150);
    glEnd();
    glBegin(GL_TRIANGLES);
        glColor3d(1,0,0);
        glVertex3d(50,3,0);
        glVertex3d(50,-3,0);
        glVertex3d(53,0,0);

        glColor3d(0,1,0);
        glVertex3d(3,50,0);
        glVertex3d(-3,50,0);
        glVertex3d(0,53,0);

        glColor3d(0,0,1);
        glVertex3d(0,3,50);
        glVertex3d(0,-3,50);
        glVertex3d(0,0,53);

    glEnd();
}

void MainWidget::glDrawScene()
{
    glDrawAxis();
    //qglColor(Qt::gray);
    glColor3d(0.5,0.5,0.5);
    QColor za(255,0,0,255);

    for(int i=0;i<id;i++)
    {
        switch(data[i].object)
        {
            case 0:
                glColor4d(255,0,0,1);
                break;
            case 1:
                glColor4d(0,255,0,1);
                break;
            case 2:
                glColor4d(0,0,255,1);
                break;
        }
        glDrawFigure(i);
    }
}
void MainWidget::glDrawFigure(int i)
{
    glCallList(backEnd->create(&data[i]));
}

void MainWidget::deleteButtonPressed()
{

        delete data;
    data = new DataBase[10];
    id = 0;
    updateGL();
    creatorBlock->comboBox->clear();
}
