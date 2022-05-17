#ifndef GRADEA_H
#define GRADEA_H
#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsItem>
#include <QString>
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPainter>

class GradeA: public QObject, public QGraphicsRectItem{
    Q_OBJECT;
private:
    QGraphicsTextItem* text;
    QTimer* timer;
public:
    GradeA(QGraphicsItem* parent = 0);
    ~GradeA(){delete text;
             delete timer;};


public slots:
    void move();
};

#endif // GRADEA_H
