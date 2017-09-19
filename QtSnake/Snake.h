#ifndef SNAKE_H
#define SNAKE_H
#include<QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QObject>
#include <QGraphicsTextItem>
#include "SnakeUnit.h"
#include <QString>

class SnakeUnit;

class Snake:public QObject
{
    Q_OBJECT

private:

public:
    int length;
    int speed;
    int size;
    int color;      
    QString threatDirection;
    QList<SnakeUnit*> body;
    QGraphicsTextItem *info;
    QString  name;
    QString direction;
    QString pic;
    QString type;
    int score;
    int count;
    bool alive;
    Snake();
    Snake(QGraphicsScene *scene, QString nam, int l);
    void destroy();
    void changeDirection(QString dir);
    QGraphicsEllipseItem *boundary;
    void changeRandomDirection(int attackLevel);
    void avoidThreat();

public slots:
    void move();

};

#endif // SNAKE_H
