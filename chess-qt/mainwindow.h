#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "gamewindow.h"
#include "loadwindow.h"

#include <QMainWindow>
#include <QDesktopWidget>
#include <QMessageBox>
#include <QDir>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QGraphicsItem>
#include <QtGui>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:
     void loadButton();
     void newButton();

private slots:
    void mkDir();
    void moveToCenter();
    void showLoad();
    void showNew();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QGraphicsPixmapItem *saver;
    QGraphicsEllipseItem *ellipse;
    LoadWindow *loadw;
    GameWindow *gamew;


};

#endif // MAINWINDOW_H
