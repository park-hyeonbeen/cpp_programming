#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

//title을 정하고, ui를 숨기며 button의 focus를 없앤다.
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Assign5");
    ui->graphicsView->hide();
    ui->pushButton->setFocusPolicy(Qt::NoFocus);

}

//소멸자
MainWindow::~MainWindow()
{
    delete ui;
    delete timer;
}

//버튼이 클릭되었을 시, 여러 object를 초기화하고 connect로 연결한 뒤 결과를 출력한다.
void MainWindow::on_pushButton_clicked()
{

    ui->pushButton->deleteLater();
    ui->graphicsView->show();
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    scene ->setSceneRect(0,0,800,800);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setFixedSize(800,800);
    ui->centralwidget->setFixedSize(800,800);

    player = new Player();
    score = new Score();
    endtimer = new EndTimer();
    player->setRect(0,0,30,30);
    player->setPos(385,770);
    scene->addItem(player);
    scene->addItem(score);
    scene->addItem(endtimer);


    timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), player, SLOT(spawn()));
    timer->start(500);

    QObject::connect(player, SIGNAL(gameover()), this, SLOT(gameover()));
    QObject::connect(player, SIGNAL(increase()), this, SLOT(increase()));
    QObject::connect(endtimer,SIGNAL(timeover()),this,SLOT(gameend()));


}

//key가 입력되면 player로 보낸다
void MainWindow::keyPressEvent(QKeyEvent *event){
    player->keyPressEvent(event);
}
//메세지 박스에 score를 띄우고, scene을 clear한 뒤, exit 한다.
void MainWindow::gameover(){
    int total = score->getScore();
    std::string sentence("Game Over\nScore: ");
    sentence = sentence + std::to_string(total);
    scene->clear();
    QMessageBox::information(this,"End",sentence.c_str());
    exit(0);

}
//score의 increase를 호출한다.
void MainWindow::increase(){
    score->increase();
}

//메세지 박스에 score를 띄우고, scene을 clear한 뒤, exit 한다.
void MainWindow::gameend(){
    int total = score->getScore();
    std::string sentence("Score: ");
    sentence = sentence + std::to_string(total);
    scene->clear();
    QMessageBox::information(this,"End",sentence.c_str());
    exit(0);
}
