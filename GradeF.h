#ifndef GRADEF_H
#define GRADEF_H
#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsItem>
#include <QString>
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPainter>



class GradeF: public QObject, public QGraphicsRectItem{
    Q_OBJECT;
private:
    QGraphicsTextItem* text;
    QTimer* timer;
public:
    GradeF(QGraphicsItem* parent = 0);
    ~GradeF(){delete text;
             delete timer;};


public slots:
    void move();
    //void collide();
};



#endif // GRADEF_H
