/*
 * Copyright (c) 2011-2014 Microsoft Mobile.
 */

#include <QApplication>
#include "TableauWidget.h"

// Lock Symbian orientation
#ifdef Q_OS_SYMBIAN
#include <eikenv.h>
#include <eikappui.h>
#include <aknenv.h>
#include <aknappui.h>
#endif

int main(int argc, char *argv[])
{
    int ret(0);

    QApplication app(argc, argv);

    // Lock Symbian orientation to landscape
#ifdef Q_OS_SYMBIAN
    CAknAppUi* appUi = dynamic_cast<CAknAppUi*> (CEikonEnv::Static()->AppUi());
    TRAP_IGNORE(
    if (appUi) {
        appUi->SetOrientationL(CAknAppUi::EAppUiOrientationLandscape);
    }
    );
#endif


    // Create widget into heap
    TableauWidget *tableauWidget = new TableauWidget();

    app.setActiveWindow(tableauWidget);

#if defined(Q_OS_WIN32)
    tableauWidget->setFixedSize(640,400);
    tableauWidget->show();
#elif defined(Q_OS_SYMBIAN) || defined(Q_WS_MAEMO_6) || defined(Q_WS_SIMULATOR)
    tableauWidget->showFullScreen();
#else
    tableauWidget->showMaximized();
#endif

    ret = app.exec();
    delete tableauWidget;

    return ret;
}

// End of file
