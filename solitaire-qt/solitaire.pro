# Copyright (c) 2011-2014 Microsoft Mobile

INCLUDEPATH += inc
TEMPLATE = app
TARGET = solitaire
VERSION = 1.7.0

SOURCES += src/main.cpp \
    src/TableauWidget.cpp \
    src/Card.cpp \
    src/SolitaireScene.cpp \
    src/CardDeck.cpp \
    src/GameLogic.cpp \
    src/Deck.cpp \
    src/SolitaireView.cpp \
    src/Button.cpp
    
HEADERS += src/TableauWidget.h \
    src/Card.h \
    src/SolitaireScene.h \
    src/CardDeck.h \
    src/GameLogic.h \
    src/Deck.h \
    src/SolitaireView.h \
    src/Button.h
    
RESOURCES = resources.qrc
QT += svg

# Symbian specific
symbian { 
    TARGET = Solitaire
    TARGET.UID3 = 0xEa8e5c91
    TARGET.EPOCHEAPSIZE = 20000 10000000
    TARGET.EPOCSTACKSIZE = 0x14000
    ICON = images/icon.svg

    # For locked orientation
    LIBS += -lcone -leikcore -lavkon
}

# Maemo 5 and Harmattan
unix:!symbian {
    BINDIR = /opt/usr/bin
    DATADIR = /usr/share
    DEFINES += \
        DATADIR=\\\"$$DATADIR\\\" \
        PKGDATADIR=\\\"$$PKGDATADIR\\\"

    target.path = $$BINDIR

    icon64.path = $$DATADIR/icons/hicolor/64x64/apps
    icon64.files += images/icons/64x64/solitaire.png

    maemo5 {
        # Maemo specific
        OTHER_FILES += qtc_packaging/debian_fremantle/*
        desktopfile.path = $$DATADIR/applications/hildon
        desktopfile.files += qtc_packaging/debian_fremantle/$${TARGET}.desktop
    }
    else {
        # Harmattan specific
        DEFINES += Q_WS_MAEMO_6
        OTHER_FILES += qtc_packaging/debian_harmattan/*
        desktopfile.path = $$DATADIR/applications
        desktopfile.files += qtc_packaging/debian_harmattan/$${TARGET}.desktop
    }

    INSTALLS += \
        target \
        desktopfile \
        icon64
}
