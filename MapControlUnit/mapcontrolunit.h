#ifndef MAPCONTROLUNIT_H
#define MAPCONTROLUNIT_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QLCDNumber>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QGridLayout>
class MapControlUnit : public QWidget
{
    Q_OBJECT
public:
    explicit MapControlUnit(QWidget *parent = 0);
    QDoubleSpinBox  *doubleSpinBox;
protected:
    QPushButton     *bStart;
    QPushButton     *bStop;
    QPushButton     *bContinue;
    QLabel          *currentTime;
public:
    QGridLayout     *mainGrid;
protected:
    QSpinBox        *timeEdit;
    void createWidget();
    void createConnects();
signals:
    void buttonStartPressed();
    void buttonStopPressed();
    void buttonSbrosPressed();
public slots:
    void start();
    void stop();
    void sbros();
};

#endif // MAPCONTROLUNIT_H
