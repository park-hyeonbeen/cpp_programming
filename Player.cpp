#include "Player.h"

//색깔을 노란색으로 설정한다.
Player::Player(QGraphicsItem* parent): QObject(), QGraphicsEllipseItem(parent){
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(collide()));
    timer->start(0);
    QBrush brush(Qt::yellow);
    setBrush(brush);
}
//key가 입력되면 player의 좌표를 확인하고 화면의 끝이 아닐 때 이동한다.
void Player::keyPressEvent(QKeyEvent * event){
    if(event->key()== Qt::Key_Left){
        if(pos().x() > 5)
            setPos(x()-10,y());
        else if(pos().x() == 5)
            setPos(x()-5,y());
    }
    else if (event->key() == Qt::Key_Right){
             if (pos().x() + 30 < 795)
             setPos(x()+10,y());
             else if(pos().x() + 30 == 795)
             setPos(x()+4,y());
    }
}
//MainWindow로부터 signal을 받아 GradeA 또는 GradeF object를 생성한다.
void Player::spawn(){
  srand(time(NULL));
  int randnum = rand()%2;
  if(randnum ==1){
      GradeA* grade = new GradeA();
      scene()->addItem(grade);
  }
  else if(randnum ==0){
      GradeF* grade = new GradeF();
      scene()->addItem(grade);
}
};

//위에서 timer와 connect되어 0ms마다 GradeA 또는 GradeF와 접촉했는지 확인하고, signal을 보낸다.
void Player::collide(){
    QList<QGraphicsItem *> colliding_items = collidingItems();

       for (int i = 0, n = colliding_items.size(); i < n; ++i){
           if (typeid(*(colliding_items[i])) == typeid(GradeA)){
               scene()->removeItem(colliding_items[i]);
               delete colliding_items[i];
               emit increase();

           }
           else if(typeid(*(colliding_items[i])) == typeid(GradeF)){
               emit gameover();
           }
}
}

