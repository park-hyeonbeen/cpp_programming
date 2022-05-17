#include "Grade.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QList>
#include <cstdlib>
#include <ctime>
#include <QPainter>

Grade::Grade(QGraphicsItem* parent): QObject(), QGraphicsRectItem(parent){


int random_pos = rand() % 760;
setPos(random_pos, 0);

setRect(0,0,40,40);

QTimer* timer = new QTimer(this);
connect(timer, SIGNAL(timeout()),this,SLOT(move()));

timer->start(20);


}


void Grade::move(){
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

