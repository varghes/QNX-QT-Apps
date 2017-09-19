#ifndef SNAKEAII_H
#define SNAKEAII_H
#include<QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QObject>
#include <QGraphicsTextItem>

class SnakeAi:public QObject
{
    Q_OBJECT

private:
    int length;
    int score;
    int size;
    int speed;
    QList<QGraphicsPixmapItem*> body;
    QList<QGraphicsTextItem *> infos;
    float x;
    float y;

public:
    QString direction;
    bool alive;
    SnakeAi(QGraphicsScene *s);

public slots:
    void move();
};

#endif // SNAKEAII_H
