#include "Stone.h"
#include "Util.h"

Stone::Stone(QGraphicsScene *scene, int mX, int mY, int x, int y):Food(scene, mX, mY, x, y)
{
    setPixmap(QPixmap(":/images/stone.png"));
    setPos(Util::random(10,mX), Util::random(10,mY));
    setScale(1);
}
