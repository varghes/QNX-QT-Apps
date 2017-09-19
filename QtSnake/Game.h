#ifndef GAME_H
#define GAME_H
#include<QTimer>
#include<QGraphicsView>
#include<QGraphicsScene>
#include<QObject>
#include "Snake.h"
#include <QKeyEvent>

class Game: public QGraphicsView
{

Q_OBJECT

public:
    QGraphicsScene *scene;
    Game(QApplication *a);
    Snake *snake;
    QList<Snake*> snakes;  
    QString direction;
    int attackLevel;
    void keyPressEvent(QKeyEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent();
    void mouseMoveEvent(QMouseEvent *event);
    void updateScore();
    void generateAi(int n);
    void sortSnakes();
    int giveSnakePos(Snake *s);

public slots:
    void addFood();
    void moveScreen();


};

#endif // GAME_H
