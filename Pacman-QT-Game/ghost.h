#ifndef GHOST_H
#define GHOST_H

#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>
class Ghost:public QGraphicsItem
{
public:
    Ghost();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void advance();
    void setgosx(int);
    void setgosy(int);
    void setDirection(int dir);
    void setColor(QString col);

    void changeGeometry() { prepareGeometryChange(); }

    QPixmap left1,left2;
    QPixmap up1,up2;
    QPixmap down1,down2;
    QPixmap right1,right2;
    QPixmap scareb,scareb1,scarew,scarew1;

    int gosx,gosy;
    int direction;
    int animestate;
    bool is_Scared,whiteb;
};

#endif // GHOST_H
