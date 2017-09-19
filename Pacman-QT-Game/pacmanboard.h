#ifndef PACMANBOARD_H
#define PACMANBOARD_H
#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QVector>
#include "ball.h"
#include "powerball.h"


class PacmanBoard : public QGraphicsItem
{

public:
    PacmanBoard();
    Ball *ball;
    PowerBall *powerball;
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void advance();
    void generateBalls();
    void AddPathPoints(int, int, int, int);
    bool canmove(QPoint);
    void fillpacpoints(int pacx,int pacy);
    void setballpoints(QVector<QPoint> points);
    void setpowerballpoints(QVector<QPoint> points);

    void changeGeometry() { prepareGeometryChange(); }

    QVector<QPoint> getballpoints();
    QVector<QPoint> getpowerballpoints();
    QPixmap mappic;
    QVector<QPoint> pacpoints,ballpoints;
    QVector<QPoint> powerballpoints;
    //QPoint peos[];
};

#endif // PACMANBOARD_H
