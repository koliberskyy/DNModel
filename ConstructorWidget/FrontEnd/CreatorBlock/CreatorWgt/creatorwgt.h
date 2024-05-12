#ifndef CREATORWGT_H
#define CREATORWGT_H

#include <QWidget>
#include <QComboBox>
#include <QLabel>
#include <QLineEdit>
#include <QGroupBox>
#include <QGridLayout>
#include <QPushButton>
#include <QOpenGLWidget>

#define SPHERE 0
#define CYLINDER 1
#define PLAST 2

class CreatorWgt : public QWidget
{
    Q_OBJECT
public:
    explicit CreatorWgt(QWidget *parent = 0);
protected slots:
    void comboChanged(int);
    void buttonPressed();
protected:
    QGridLayout *gridMain;
    QComboBox *comboFigure;
    QLabel *l1;
    QLabel *l2;
    QLabel *l3;
    QLabel *l4;
    QLineEdit *le1;
    QLineEdit *le2;
    QLineEdit *le3;
    QLineEdit *le4;
 public:
    QPushButton *pb;

    // <double><Sphere><Radius>
    double dSR;
    double dCR;
    double dCW;
    double dPH;
    double dPW;
    //----------

    int nFigureTrigger;
};

#endif // CREATORWGT_H
