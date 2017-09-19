#include <QApplication>
#include "calc.h"

int main (int argc, char * argv[])
{
    QApplication app (argc, argv);
    calc cal;
    cal.show();
    return app.exec();
}
