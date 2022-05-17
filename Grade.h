#ifndef GRADE_H
#define GRADE_H
#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QString>

class Grade: public QObject, public QGraphicsRectItem{
    Q_OBJECT;
private:
    QGraphicsTextItem* text;
    std::string Alphabet;
public:
    Grade(QGraphicsItem* parent = 0);
    ~Grade(){delete text;};


public slots:
    void move();
};


#endif // GRADE_H
