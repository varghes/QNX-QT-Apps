#include "Game.h"
#include "Util.h"
#include <QApplication>


Game *g;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Util::readSettings();
    g = new Game(&a);
    g->show();

    return a.exec();
}
