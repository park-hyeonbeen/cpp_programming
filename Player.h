#ifndef PLAYER_H
#define PLAYER_H


#include <QGraphicsEllipseItem>
#include <QObject>
#include <QGraphicsItem>
#include "Score.h"
#include "GradeA.h"
#include "GradeF.h"
#include <cstdlib>
#include <ctime>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QList>
#include <QTimer>
#include <QPainter>

class Player:public QObject, public QGraphicsEllipseItem{
    Q_OBJECT
private:
    QTimer* timer;
public:
    Player(QGraphicsItem* parent = 0);
    ~Player(){delete timer;};
    void keyPressEvent(QKeyEvent* event);

public slots:
    void spawn();
    void collide();
signals:
    void gameover();
    void increase();
};



#endif // PLAYER_H
