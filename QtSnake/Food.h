#ifndef FOOD_H
#define FOOD_H
#include <QGraphicsPixmapItem>

class Food: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    int speed;
    int life;
    int maxLife;
    Food(QGraphicsScene *scene, int mX, int mY, int x, int y);

public slots:   
    void countLife();

};

#endif // FOOD_H
