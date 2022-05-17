#include "GradeA.h"


//테두리 색깔과 위치, 내부에 출력되는 글자를 정한다.
GradeA::GradeA(QGraphicsItem* parent): QObject(), QGraphicsRectItem(parent){


    QPen pen(Qt::blue);
    text = new QGraphicsTextItem();
    text->setPlainText(QString("A"));
    setPen(pen);


int random_pos = rand() % 760;
setPos(random_pos, 0);

setRect(0,0,40,40);

timer = new QTimer(this);
connect(timer, SIGNAL(timeout()),this,SLOT(move()));

timer->start(20);




}


//위의 timer과 connect되어 20ms마다 y좌표, text의 y좌표를 변경한다.
void GradeA::move(){
    text->setPos(this->x(),this->y());
    if(y()==0)
        scene()->addItem(text);
    setPos(x(),y()+10);
    text->setPos(this->x(),this->y());

    if (pos().y() > 800){
        scene()->removeItem(this);
        delete this;
    }

}
