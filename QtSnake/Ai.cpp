#include "Ai.h"
#include "Game.h"
#include "Util.h"
#include "SnakeUnit.h"
#include <QTimer>
#include <qdebug.h>

extern Game *g;

Ai::Ai(QGraphicsScene *scene, QString nam, int x, int y, QString dir, int l):Snake(scene, nam, l)
{
    //set defaults
    alive = true;

    QList<QString> aiTypes;
    aiTypes<<"chipku"<<"normal"<<"courage"<<"paytu";
    type = aiTypes.at(Util::random(0,aiTypes.size()-1));
    info->setPlainText(nam + QString(" ") + type);
    info->setFont(QFont("calibri", 7));
    score = Util::random(1,5);
    crawling = 0;

    for(int i=0; i<length; i++){
        body[i]->setPos(x-i*size, y);
    }
    info->setPos(body[0]->x()+10, body[0]->y()+10);
    info->setDefaultTextColor(Qt::yellow);
    changeDirection(dir);
}

