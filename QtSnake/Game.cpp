#include "Game.h"
#include "Food.h"
#include "Stone.h"
#include "Mushroom.h"
#include "Snake.h"
#include "Ai.h"
#include "Util.h"
#include <QGraphicsRectItem>
#include <QTimer>
#include <QDebug>
#include <qapplication.h>
#include <math.h>

QApplication *app;
QGraphicsTextItem *scoreBoard;
QGraphicsRectItem *back;
int speed = 1;

Game::Game(QApplication *a)
{
    //set defaults  
    app = a;
    attackLevel = 4;

    //full screen
    setFixedHeight(Util::screenHeight());
    setFixedWidth(Util::screenWidth());

    //create and configure scene
    scene = new QGraphicsScene(this);    
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//scroll bar
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff); //scroll bar    
    setWindowFlags(Qt::FramelessWindowHint); //window border
    scene->setSceneRect(0,0,Util::screenWidth(),Util::screenHeight());
    setScene(scene);

    //background
    back = new QGraphicsRectItem(-Util::screenWidth(), -Util::screenHeight(), 3*Util::screenWidth(), 3*Util::screenHeight());
    back->setZValue(-1000);
    back->setBrush(QBrush(QPixmap(":/images/back.jpg")));
    scene->addItem(back);

    //create main player of length 3
    snake = new Snake(scene, "Bibhuti", 3);
    Util::addReservedName("Bibhuti");
    snakes.append(snake);

    //add 10 AIs
    generateAi(9);

    //add 200 foods
    for(int i=0; i<50; i++) new Food(scene, Util::screenWidth()-10, Util::screenHeight()-10, -1, -1);

    //score    
    scoreBoard = new QGraphicsTextItem();
    scoreBoard->setPos(30,30);
    scoreBoard->setDefaultTextColor(Qt::white);
    scoreBoard->setFont(QFont("calibri", 10));
    scene->addItem(scoreBoard);
    scoreBoard->setZValue(10);
    updateScore();

    //timer to add food
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(addFood()));
    timer->start(1000);

    //timer to move screen
    QTimer *screenTimer = new QTimer();
    connect(screenTimer, SIGNAL(timeout()), this, SLOT(moveScreen()));
    screenTimer->start(100);
}

void Game::keyPressEvent(QKeyEvent *event){

    if(event->key() == Qt::Key_Right && snake->direction != "left"){
        snake->changeDirection("right");
    }

    else if(event->key() == Qt::Key_Left && snake->direction != "right"){
        snake->changeDirection("left");
    }

    else if(event->key() == Qt::Key_Up && snake->direction != "down"){
        snake->changeDirection("up");
    }

    else if(event->key() == Qt::Key_Down && snake->direction != "up"){
       snake->changeDirection("down");
    }

    else if(event->key() == Qt::Key_Space){
        snake->alive = true;
    }

    else if(event->key() == Qt::Key_Escape){
        app->exit();
        qDebug()<<"Exited";
    }
    else if(event->key() == Qt::Key_Control){
        snake->speed = 15;
    }
    else if(event->key() == Qt::Key_Alt){
        snake->speed = 6;
    }

}

int iX, iY, fX, fY, mouseDown = 0;
void Game::mousePressEvent(QMouseEvent *event)
{
    mouseDown = 1;
    iX = event->x();
    iY = event->y();
}

void Game::mouseReleaseEvent()
{
    mouseDown = 0;
    snake->changeDirection(Util::giveDirection(iX, iY, fX, fY));
}

void Game::mouseMoveEvent(QMouseEvent *event)
{
    if(mouseDown == 1){
        fX = event->x();
        fY = event->y();
    }
}

void Game::updateScore()
{    
    //increase attack level
    if(snake->score > 5) attackLevel = snake->score + 1;

    sortSnakes();

    QString boardText = "";
    Snake *s;
    for(int i=1; i<=snakes.size(); i++){
        s = snakes.at(i-1);
        boardText += "\n" + QString("#") + QString::number(i) +  QString("   ") + s->name +  QString("    ") + QString::number(s->score);
    }
    boardText += "\n\n Your Score : " + QString::number(snake->score);
    boardText += "\n Position : " + QString::number(snakes.indexOf(snake)+1) + QString(" out of ") + QString::number(snakes.size());
    scoreBoard->setPlainText(boardText);
}

void Game::generateAi(int n)
{
    //keep snake out of the screen
    int r;
    int xi = 0, yi = 0;
    QString dir;

    for(int i=0; i<n; i++){
        r = Util::random(1,4);

        switch(r){
            case 1:
                //top
                xi = Util::random(10,Util::screenWidth()-10);
                yi = Util::random(-100, -200);
                dir = "down";
                break;

            case 2:
                //bottom
                xi = Util::random(10,Util::screenWidth()-10);
                yi = Util::random(Util::screenWidth() + 100, Util::screenWidth() + 200);
                dir = "up";
                break;

            case 3:
                //left
                xi = Util::random(-100, -200);
                yi = Util::random(10, Util::screenHeight() - 10);
                dir = "right";
                break;

            case 4:
                //right
                xi = Util::random(Util::screenWidth() + 100, Util::screenWidth() + 200);
                yi = Util::random(10, Util::screenHeight()- 10);
                dir = "left";
                break;
        }

        //random and different name
        Ai *ai = new Ai(scene, Util::randomSnakeName(), xi, yi, dir, Util::random(3, 10));
        snakes.append(ai);
    }
}

void Game::sortSnakes()
{
    Snake *temp;
    for(int i=0; i<snakes.size(); i++){
        for(int j=i; j<snakes.size(); j++){
            if(snakes.at(i)->score < snakes.at(j)->score){
                //temp = i;
                //i = j
                //j = temp
                temp = snakes[i];
                snakes.replace(i,snakes[j]);
                snakes.replace(j,temp);
            }

        }
    }
}

int Game::giveSnakePos(Snake *s)
{
    return snakes.indexOf(s);
}

void Game::moveScreen()
{
    if(snake->alive == true){

        if(snake->direction == "right"){
            back->setPos(back->x()+speed, back->y());
        }
        else if(snake->direction == "left"){
            back->setPos(back->x()-speed, back->y());
        }
        else if(snake->direction == "up"){
            back->setPos(back->x(), back->y()-speed);
        }
        else if(snake->direction == "down"){
            back->setPos(back->x(), back->y()+speed);
        }
    }
}

void Game::addFood()
{
    if(snake->alive){

        for(int i=0; i<5; i++) new Food(scene, Util::screenWidth()-10, Util::screenHeight()-10, -1, -1);

        if(Util::random(1,10) == 5) new Stone(scene, Util::screenWidth()-10, Util::screenHeight()-10, -1, -1);

        if(Util::random(1,10) == 3) new Mushroom(scene, Util::screenWidth()-10, Util::screenHeight()-10, -1, -1);
    }
}




