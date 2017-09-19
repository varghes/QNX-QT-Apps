#ifndef BALL_H
#define BALL_H

#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>

class Ball : public QGraphicsItem
{
public:
    Ball();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void drawballs(QPainter *painter);
    void setpoints(QVector<QPoint> points);
    void removepoint(QPoint p);


    void generatePointPixmap();

    int ballx,bally;
    int ballw,ballh;
    QPixmap ballpix;
    QRectF rec;
    QVector<QPoint> points;

};
#endif // BALL_H
