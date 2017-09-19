
#-------------------------------------------------
#
# Project created by QtCreator 2016-02-17T12:19:28
#
#-------------------------------------------------

QT       += core gui \
         multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BlackJack
TEMPLATE = app


SOURCES += main.cpp \
    mycard.cpp \
    myscene.cpp \
    mypack.cpp \
    mybutton.cpp

HEADERS  += \
    mybutton.h \
    mycard.h \
    myscene.h \
    mypack.h

FORMS    +=

RESOURCES += \
    cards.qrc \
    sounds.qrc

DISTFILES += \
    my.pack
