#include "Score.h"
#include <QFont>

//score를 0으로 초기화하고, 출력한다.
Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent){
    score = 0;
    setPlainText(QString("Score: ") + QString::number(score)); // Score: 0
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",16));
}

//score를 1 증가시키고, 출력한다.
void Score::increase(){
    score++;
    setPlainText(QString("Score: ") + QString::number(score)); // Score: 1
}

//score를 return한다.
int Score::getScore(){
    return score;
}
