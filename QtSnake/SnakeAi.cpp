#include "SnakeAi.h"
#include <SnakeUnit.h>
#include "Food.h"
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QTimer>
#include <QDebug>
#include<QThread>
#include <stdlib.h>
#include<typeinfo>

QGraphicsScene *scene;
int random2(int min, int max){
    return (rand()%(max-min + 1) + min);
}

SnakeAi::SnakeAi(QGraphicsScene *s)
{
    scene = s;
    length = 10;
    size = 10;
    alive = false;
    direction = "right";
    score = 0;
    speed = size;

    //draw snake body
    int startX = random2(200, 800);
    int startY = random2(200,800);
    QString pic = ":/images/snakeUnit"+QString::number(random2(1,7))+".png";
    for(int i=0; i<length; i++){
        SnakeUnit *e = new SnakeUnit();
        e->setPixmap(QPixmap(pic));
        e->setPos(startX-i*size, startY);
        s->addItem(e);
        body.append(e);

        //info
//        QGraphicsTextItem *ii = new QGraphicsTextItem();
//        ii->setPlainText(QString::number(i));
//        ii->setPos(start-i*size, start);
//        s->addItem(ii);
//        infos.append(ii);
    }

    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(100);
}

void SnakeAi::move()
{

    //change direction randomly
    if((rand()%100) % 3 == 0){

        //change direction
        int r = rand()%4;

        if(r==0 && direction != "left"){
            direction = "right";
        }
        else if(r==1 && direction != "right"){
            direction = "left";
        }
        else if(r==2 && direction != "down"){
            direction = "up";
        }
        else if(r==3 && direction != "up"){
            direction = "down";
        }

    }

    //move snake
    for(int i = body.size()-1; i>=0; i--){

        //body
        if(i != 0){
            body[i]->setX(body[i-1]->x());
            body[i]->setY(body[i-1]->y());

//            infos[i]->setX(infos[i-1]->x());
//            infos[i]->setY(infos[i-1]->y());
        }

        //head
        else{
                //move according to direction
                if(direction == "right"){
                    body[0]->setX(body[0]->x()+speed);
                   // infos[0]->setX(infos[0]->x()+speed);
                }

                else if(direction == "left"){
                     body[0]->setX(body[0]->x()-speed);
                   //  infos[0]->setX(infos[0]->x()-speed);
                }

                else if(direction == "up"){
                    body[0]->setY(body[0]->y()-speed);
                   // infos[0]->setY(infos[0]->y()-speed);
                }

                else if(direction == "down"){
                    body[0]->setY(body[0]->y()+speed);
                   // infos[0]->setY(infos[0]->y()+speed);
                }

            }

    }

    //check out bounds
    if(body[0]->x() > scene->width()) body[0]->setX(0);
    else if(body[0]->x() < 0) body[0]->setX(scene->width());
    else if(body[0]->y() < 0) body[0]->setY(scene->height());
    else if(body[0]->y() > scene->height()) body[0]->setY(0);

    //collission with food
    QList<QGraphicsItem *> colliding_items = body[0]->collidingItems();
    for(int i=0; i<colliding_items.size(); i++){
        if(typeid(*(colliding_items[i])) == typeid(Food)){
            body[0]->scene()->removeItem(colliding_items[i]);
            delete colliding_items[i];
            score++;
        }
    }
}
