#include "Game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include <QDebug>

Game::Game(QWidget* parent){

    scene = new QGraphicsScene();
    player = new Player();
    score = new Score();
}

