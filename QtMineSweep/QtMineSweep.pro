#-------------------------------------------------
#
# Project created by QtCreator 2016-06-29T19:28:38
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtMineSweep
TEMPLATE = app


SOURCES += main.cpp\
        main_game_window.cpp \
    game_model.cpp

HEADERS  += main_game_window.h \
    game_model.h

FORMS    += maingamewindow.ui

RESOURCES += \
    resource.qrc
