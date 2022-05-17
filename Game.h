#ifndef GAME_H
#define GAME_H
#include <QWidget>
#include "Player.h"
#include "Grade.h"
#include "Score.h"
#include <QGraphicsScene>
#include <QTimer>
#include <QGraphicsView>

class Game{
public:
    Game(QWidget* parent = 0);
    Player* player;
    QGraphicsScene* scene;
    Score* score;

};
#endif // GAME_H
