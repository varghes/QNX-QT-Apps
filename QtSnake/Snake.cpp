#include "Snake.h"
#include "Food.h"
#include "Stone.h"
#include "Mushroom.h"
#include "Ai.h"
#include "Game.h"
#include "Util.h"
#include "SnakeUnit.h"
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QTimer>
#include <QDebug>
//#include <typeinfo.h>
#include <typeinfo>
#include <stdlib.h>
#include <QDesktopWidget>

extern Game *g;
QGraphicsScene *sc;
QTimer *timer;

Snake::Snake()
{

}

Snake::Snake(QGraphicsScene *s, QString nam, int l)
{
    sc = s;
    length = l;
    size = 6;
    alive = false;
    direction = "right";
    score = 1;
    count = 0;    
    speed = size+2;
    name = nam;
    type = "me";

    //snake body
    int startX = Util::screenWidth()/2;
    int startY = Util::screenHeight()/2;
    color = Util::randomSnakeColor();
    pic = ":/images/snakeUnit"+QString::number(color)+".png";
    for(int i=0; i<length; i++){
        SnakeUnit *e = new SnakeUnit(name, this);
        if(i==0){
            e->setPixmap(QPixmap(":/images/snakeUnit"+QString::number(color)+"Head.png"));
            e->setTransformOriginPoint(e->pixmap().width()/2, e->pixmap().height()/2);
        }
        else{           
             e->setPixmap(QPixmap(pic));
             e->setZValue(-100);            
        }
        e->setPos(startX-i*size, startY);
        s->addItem(e);
        body.append(e);       
    }
    body[0]->setRotation(90);

    //boundary
    boundary = new QGraphicsEllipseItem(0, 0, 100, 100);
    boundary->setPen(QPen(Qt::transparent));
    boundary->setZValue(-1);
    s->addItem(boundary);

    //snake name
    info = new QGraphicsTextItem();
    info->setFont(QFont("calibri", 9));
    info->setPlainText(name);
    info->setDefaultTextColor(Qt::white);
    info->setPos(startX+10, startY+10);
    s->addItem(info);

    //move timer
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(100);
}

void Snake::move()
{

    if(g->snake->alive == true){

        //move snake
        for(int i = body.size()-1; i>=0; i--){

            //body
            if(i != 0){
                body[i]->setX(body[i-1]->x());
                body[i]->setY(body[i-1]->y());               
            }

            //head
            else{
                    //move according to direction
                    if(direction == "right"){
                        body[0]->setX(body[0]->x()+speed);
                    }

                    else if(direction == "left"){
                         body[0]->setX(body[0]->x()-speed);
                    }

                    else if(direction == "up"){
                        body[0]->setY(body[0]->y()-speed);
                    }

                    else if(direction == "down"){
                        body[0]->setY(body[0]->y()+speed);
                    }

                }

        }

        //move boundary
        boundary->setX(body[0]->x()-boundary->rect().width()/2);
        boundary->setY(body[0]->y()-boundary->rect().height()/2);

        //move snake name
        info->setX(body[0]->x()+10);
        info->setY(body[0]->y()+10);

        //acc according to ai type
        if(type == "normal"){
            //change direction randomly with low attack level
            changeRandomDirection(1);
        }

        else if(type == "chipku"){
             avoidThreat();

            //change direction randomly according to attack level
            changeRandomDirection(g->attackLevel);
        }

        else if(type == "courage"){
            //move away from threat if present
            avoidThreat();

            //change direction randomly with low attack level
            changeRandomDirection(1);
        }

        else if(type == "paytu"){

            avoidThreat();

            //eat nearby food
            QList<QGraphicsItem *> food_items = boundary->collidingItems();
            for(int i=0; i<food_items.size(); i++){
                if(typeid(*(food_items[i])) == typeid(Food) || (typeid(*(food_items[i])) == typeid(Mushroom))){
                    //if food has minimum life of 2 seconds
                    Food *f = (Food*)food_items[i];
                    if(f->life > 1){
                        QString d = Util::giveDirection(body[0]->x(), body[0]->y(), f->x(), f->y());
                        if(d != Util::oppositeDirection(direction)){
                            changeDirection(d);
                            qDebug()<<"Food";
                        }
                    }
                }
            }
        }

        //check collssion
        QList<QGraphicsItem *> colliding_items = body[0]->collidingItems();
        for(int i=0; i<colliding_items.size(); i++){

            //food
            if(typeid(*(colliding_items[i])) == typeid(Food)){

                body[0]->scene()->removeItem(colliding_items[i]);
                delete colliding_items[i];                
                count+=2;

                //update length at each 10 score
                if(count > 10){
                    score++;
                    count = 0;
                    g->updateScore();

                    //append one unit
                    SnakeUnit *e = new SnakeUnit(name, this);
                    e->setPixmap(QPixmap(pic));
                    e->setPos(-100,-100);
                    body[0]->scene()->addItem(e);
                    body.append(e);
                }
            }

            // Mushroom
            else if(typeid(*(colliding_items[i])) == typeid(Mushroom)){
                g->scene->removeItem(colliding_items[i]);
                delete colliding_items[i];
                count+=5;
                g->updateScore();
            }

            //stone
            else if(typeid(*(colliding_items[i])) == typeid(Stone)){               
                destroy();
                break;
            }

            //other snake
            else if(typeid(*(colliding_items[i])) == typeid(SnakeUnit) && ((SnakeUnit*)colliding_items[i])->parent != this){
                qDebug()<<"Collission " + name + " : " + ((SnakeUnit*)colliding_items[i])->name;
                destroy();
                break;
            }

        }

        //check screen-bounds
        if(body[0]->x() > sc->width()) body[0]->setX(0);
        else if(body[0]->x() < 0) body[0]->setX(sc->width());
        else if(body[0]->y() < 0) body[0]->setY(sc->height());
        else if(body[0]->y() > sc->height()) body[0]->setY(0);
     }
}

void Snake::destroy(){

    //remove yourself and turn into clouds
    for(int i=0; i<body.size(); i++){
        SnakeUnit *s = body[i];
        new Food(sc, 1, 1, s->x(), s->y());
        g->scene->removeItem(s); //remove body from scene
    }
     g->scene->removeItem(info); //remove info from scene
    alive = false;
    g->snakes.removeOne(this);
    Util::removeReservedName(this->name);
    Util::removeReservedColor(this->color);
     g->scene->removeItem(this->boundary);

    //delete ai from memory
    if(type == "ai"){        
        delete this;
    }

    //add new snake
    g->generateAi(1);
}

void Snake::changeDirection(QString dir){
    if(dir=="right" && direction != "left"){
        direction = "right";
        body[0]->setRotation(0);
        body[0]->setRotation(90);
    }
    else if(dir=="left" && direction != "right"){
        direction = "left";
        body[0]->setRotation(0);
        body[0]->setRotation(-90);
    }
    else if(dir=="up" && direction != "down"){
        direction = "up";
        body[0]->setRotation(0);
    }
    else if(dir=="down" && direction != "up"){
        direction = "down";
        body[0]->setRotation(0);
        body[0]->setRotation(180);
    }
}

void Snake::changeRandomDirection(int attackLevel){
    if(Util::random(0,10) % 2 == 0){

        //change direction
        int r = Util::random(0,3+attackLevel);

        if(r==0 && direction != "left"){
            changeDirection("right");
        }
        else if(r==1 && direction != "right"){
            changeDirection("left");
        }
        else if(r==2 && direction != "down"){
            changeDirection("up");
        }
        else if(r==3 && direction != "up"){
            changeDirection("down");
        }

        //move towards the player
        else if(r>3){
            QString d = Util::giveDirection(body[0]->x(), body[0]->y(), g->snake->body[0]->x(), g->snake->body[0]->y());
            if(direction != Util::oppositeDirection(d)) changeDirection(d);
        }
    }
}

void Snake::avoidThreat(){
    bool threat = false;
    int threatPointX, threatPointY;
    QList<QGraphicsItem *> boundary_items = boundary->collidingItems();
    for(int i=0; i<boundary_items.size(); i++){
        //if its other's boundary or body
        if(typeid(*(boundary_items[i])) == typeid(QGraphicsEllipseItem) || (typeid(*(boundary_items[i])) == typeid(SnakeUnit)) || (typeid(*(boundary_items[i])) == typeid(Stone))){
            threat = true;
            threatPointX = (boundary_items[i])->x();
            threatPointY = (boundary_items[i])->y();
        }
    }
    if(threat == true){
        QString d = Util::giveDirection(body[0]->x(), body[0]->y(), threatPointX, threatPointY);
        if(d != Util::oppositeDirection(direction)){
            changeDirection(Util::oppositeDirection(d));
            qDebug()<<"Threat kiled";
        }
    }
}
