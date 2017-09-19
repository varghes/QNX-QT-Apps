#-------------------------------------------------
#
# Project created by QtCreator 2016-07-11T10:49:28
#
#-------------------------------------------------

QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtLianliankan
TEMPLATE = app


SOURCES += main.cpp\
        main_game_window.cpp \
    game_model.cpp

HEADERS  += main_game_window.h \
    game_model.h

FORMS    += main_game_window.ui

RESOURCES += \
    res.qrc
