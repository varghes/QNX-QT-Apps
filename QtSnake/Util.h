#ifndef UTIL_H
#define UTIL_H
#include <QString>
#include <QList>

class Util
{
public:
    Util();    
    static int random(int min, int max);
    static int screenWidth();
    static int screenHeight();
    static void readSettings();
    static void addReservedName(QString s);
    static void removeReservedName(QString s);
    static QString randomSnakeName();
    static int randomSnakeColor();
    static void removeReservedColor(int c);
    static QString giveDirection(int iX, int iY, int fX, int fY);
    static QString oppositeDirection(QString dir);


};

#endif // UTIL_H
