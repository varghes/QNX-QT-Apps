#-------------------------------------------------
#
# Project created by QtCreator 2015-08-24T11:15:38
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = chess-qt
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    loadwindow.cpp \
    gamewindow.cpp

HEADERS  += mainwindow.h \
    loadwindow.h \
    gamewindow.h

FORMS    += mainwindow.ui \
    loadwindow.ui \
    gamewindow.ui

RESOURCES += \
    images.qrc

OTHER_FILES +=
