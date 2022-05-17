#include "EndTimer.h"

//EndTimer 생성자, time을 출력하고, color와 pont를 정한다.
EndTimer::EndTimer(QGraphicsItem *parent): QGraphicsTextItem(parent){
    time = 30;
    endtimer = new QTimer();
    setPlainText(QString("Time: ") + QString::number(time)); // Score: 0
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",16));
    setPos(0,20);

    connect(endtimer,SIGNAL(timeout()),this,SLOT(time_goes()));
    endtimer->start(10);
}

//위의 endtimer와 connect되어 0.01초마다 text가 update된다.
void EndTimer::time_goes() {

    time = time-0.01;
    setPlainText(QString("Time: ") + QString::number(time)); // Score: 0

    if(time <= 0){

        emit timeover();
}
}
