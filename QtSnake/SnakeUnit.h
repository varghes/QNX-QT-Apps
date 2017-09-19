#ifndef SNAKEUNIT_H
#define SNAKEUNIT_H
#include <QGraphicsPixmapItem>
#include "snake.h"

class Snake;
class SnakeUnit: public QGraphicsPixmapItem
{
public:
    SnakeUnit(QString n, Snake *p);
    QString name;
    Snake *parent;
};

#endif // SNAKEUNIT_H
