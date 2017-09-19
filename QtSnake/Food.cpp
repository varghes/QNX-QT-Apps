#include "Food.h"
#include "Game.h"
#include "Util.h"
#include<QGraphicsScene>
#include <QTimer>

extern Game *g;

Food::Food(QGraphicsScene *scene, int mX, int mY, int x=-1, int y=-1)
{
    life = 0;
    maxLife = Util::random(10,15);
    setZValue(-100);

    if(x == -1 && y == -1){
        //set according to given data
        setPixmap(QPixmap(":/images/f"+ QString::number(Util::random(1,7)) + ".png"));
        setPos(Util::random(10,mX), Util::random(10,mY));
    }
    else{
        //set randomly
        setPixmap(QPixmap(":/images/f"+ QString::number(Util::random(1,7)) + ".png"));
        setPos(x, y);
    }

    //set random scale
    int r = Util::random(1,3);
    if(r == 1)setScale(1);
    else if(r == 2)setScale(0.5);
    else if(r == 3)setScale(0.25);

    scene->addItem(this);

    //timer to count life
    QTimer *countTimer = new QTimer();
    connect(countTimer, SIGNAL(timeout()), this, SLOT(countLife()));
    countTimer->start(1000);
}

void Food::countLife()
{
    life++;
    if(life == maxLife){
        g->scene->removeItem(this);
        delete this;
    }
}
