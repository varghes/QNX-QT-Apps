#include "Mushroom.h"
#include "Util.h"

Mushroom::Mushroom(QGraphicsScene *scene, int mX, int mY, int x, int y):Food(scene, mX, mY, x, y)
{
    setPixmap(QPixmap(":/images/mush"+QString::number(Util::random(1,2))+".png"));
    setPos(Util::random(10,mX), Util::random(10,mY));
    setScale(1);
}
