#ifndef TIMER_H
#define TIMER_H

#include <QObject>
#include <time.h>
#include <QTime>
#include <QDateTime>
#include <QDate>
class Timer : public QObject
{
    Q_OBJECT
public:
    explicit Timer(QObject *parent = 0);
    ~Timer();
    void waitSomeSec(int sec);
    bool trigger;
    int time;

signals:
    void goMf();
    //Возвращают текущие время и дату
    void currDate(QDate);
    void currTime(QTime);

public slots:
    void runTimer(int t);
    void run();
    void stopTimer();
private:
    QDate *currentDate;
    QTime *currentTime;
};

#endif // TIMER_H
