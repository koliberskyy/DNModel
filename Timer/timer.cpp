#include "timer.h"

Timer::Timer(QObject *parent) : QObject(parent)
{
    trigger=false;
    time = 1;
    currentDate= new QDate;
    currentTime= new QTime;
}

Timer::~Timer()
{
    delete currentDate;
    delete currentTime;
}

void Timer::waitSomeSec(int sec)
{
    clock_t end = clock()+sec*CLOCKS_PER_SEC;
    while(clock()<end){ };
}

void Timer::runTimer(int t)
{
   while(true)
   {
       waitSomeSec(t);
       if(trigger=true)
       {
           emit goMf();
       }
       *currentDate = QDate::currentDate();
       *currentTime = QTime::currentTime();
       emit currDate(*currentDate);
       emit currTime(*currentTime);
   }
}
void Timer::run()
{
    trigger=true;
    runTimer(time);
}
void Timer::stopTimer()
{
    trigger=false;
}
