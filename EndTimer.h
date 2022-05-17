#ifndef ENDTIMER_H
#define ENDTIMER_H
#include <QGraphicsTextItem>
#include <QGraphicsScene>
#include <QTimer>
#include <QObject>

class EndTimer: public QGraphicsTextItem {
    Q_OBJECT
private:
    double time;
    QTimer* endtimer;
public:
    EndTimer(QGraphicsItem* parent = 0);
    ~EndTimer(){delete endtimer;};
public slots:
    void time_goes();
signals:
    void timeover();
};


#endif // ENDTIMER_H
