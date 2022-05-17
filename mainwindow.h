#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "Player.h"
#include "Score.h"
#include "EndTimer.h"
#include <string>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_pushButton_clicked();
    void keyPressEvent(QKeyEvent* event);
    void gameover();
    void increase();
    void gameend();
private:
    Ui::MainWindow *ui;
    Player* player;
    QGraphicsScene* scene;
    Score* score;
    EndTimer* endtimer;
    QTimer* timer;
};
#endif // MAINWINDOW_H
