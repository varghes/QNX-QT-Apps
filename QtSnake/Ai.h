#ifndef AAI_H
#define AAI_H
#include <Snake.h>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>

class Ai:public Snake
{
    Q_OBJECT
public:
    Ai(QGraphicsScene *scene, QString nam, int x, int y, QString dir, int l);
    int crawling;    

public slots:


};

#endif // AAI_H
