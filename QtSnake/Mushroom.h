#ifndef MUSHROOM_H
#define MUSHROOM_H
#include "Food.h"

class Mushroom: public Food
{
public:
    Mushroom(QGraphicsScene *scene, int mX, int mY, int x, int y);
};

#endif // ILLFOOD_H
