#include "ball.h"

Ball::Ball()
{
    ballx=0;
    bally=0;
    ballw=5;
    ballh=5;

    generatePointPixmap();
}

QRectF Ball::boundingRect() const
{
    return QRect(0, 0, 450, 550);
}

void Ball::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    for(int i=0;i<points.size();i++){
        painter->drawPixmap( points[i].x(), points[i].y(), ballpix );
    }
}

void Ball::drawballs(QPainter *painter)
{
    for(int i=0;i<points.size();i++){
        painter->drawPixmap( points[i].x(), points[i].y(), ballpix );
    }
}

void Ball::setpoints(QVector<QPoint> points)
{
    this->points.clear();
    this->points=points;
}

void Ball::removepoint(QPoint p)
{

}

void Ball::generatePointPixmap()
{
    QRect bounds = QRect(0, 0, 3, 3);

    QPainter painter;

    ballpix = QPixmap(bounds.size());
    ballpix.fill(Qt::transparent);
    painter.begin(&ballpix);

    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(Qt::NoPen);
    painter.setBrush(Qt::white);
    painter.drawEllipse(0, 0, 3, 3);

}
