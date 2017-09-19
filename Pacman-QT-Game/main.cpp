#include <QApplication>
#include "options.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Options o;
    o.show();

    return a.exec();
}
