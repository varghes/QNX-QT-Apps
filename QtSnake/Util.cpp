#include "Util.h"
#include "Game.h"
#include <QDesktopWidget>

//extern Game *g;
QList<QString> snakeNames;
QList<QString> reservedNames;

QList<int> snakeColors;
QList<int> reservedColors;

Util::Util()
{

}

int Util::random(int min, int max)
{
    return (rand()%(max-min + 1) + min);
}

int Util::screenWidth()
{
    QDesktopWidget widget;
    return widget.screenGeometry(-1).width();
}

int Util::screenHeight()
{
    QDesktopWidget widget;
    return widget.screenGeometry(-1).height();
}

void Util::readSettings()
{
    snakeNames<<"Ram"<<"Shyam"<<"Hari"<<"Harry"<<"Potter"<<"John"<<"David"<<"Amen"<<"Rambo"<<
             "James"<<"Leo"<<"Bucky"<<"Chao"<<"Ben"<<"Doug"<<"Elvin"<<"Adam"<<"Eve"<<"Ferros"
             <<"Linus"<<"Ghost"<<"{code}"<<"Hulk"<<"Widow"<<"IronMan"<<"Jocker"<<"Batman";

    snakeColors<<1<<2<<3<<4<<5<<6<<7<<8<<9<<10;
}

void Util::addReservedName(QString s)
{
    reservedNames.append(s);
}

void Util::removeReservedName(QString s)
{
    reservedNames.removeOne(s);
}


QString Util::randomSnakeName()
{
    QString name = "";
    repeat:
    name = snakeNames.at(random(0, snakeNames.size()-1));
    if(reservedNames.indexOf(name) > -1)goto repeat;
    reservedNames.append(name);
    return name;
}

int Util::randomSnakeColor()
{
    int color = 0;
    repeat:
    color = snakeColors.at(random(0, snakeColors.size()-1));
    if(reservedColors.indexOf(color) > -1)goto repeat;
    reservedColors.append(color);
    return color;
}

void Util::removeReservedColor(int c)
{
    reservedColors.removeOne(c);
}

QString Util::giveDirection(int iX, int iY, int fX, int fY)
{
    //determine right/left or up/down
    int dX = (fX-iX);
    int dY = (fY-iY);

    //right-left
    if(abs(dX) > abs(dY)){
        if(dX < 0){
            return(QString("left"));
        }
        else{
            return(QString("right"));
        }
    }
    //up-down
    else{
        if(dY < 0){
            return(QString("up"));
        }
        else{
            return(QString("down"));
        }
    }
    return "right";
}

QString Util::oppositeDirection(QString dir)
{
    if(dir == "right") return QString("left");
    else if(dir == "left") return QString("right");
    else if(dir == "up") return QString("down");
    else if(dir == "down") return QString("up");

    return "right";
}

