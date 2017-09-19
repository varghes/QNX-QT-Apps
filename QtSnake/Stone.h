#ifndef STONE_H
#define STONE_H
#include "Food.h"

class Stone: public Food
{
public:
    Stone(QGraphicsScene *scene, int mX, int mY, int x, int y);
};

#endif // SSTONE_H
