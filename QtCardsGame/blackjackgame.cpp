#include <QGraphicsScene>
#include <QApplication>
#include <QgraphicsView>
#include <mybutton.h>
#include <QGraphicsPixmapItem>
#include<QMainWindow>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // create a scene
    QGraphicsScene * scene = new QGraphicsScene();

    //create mainwindow
    QMainWindow * window = new QMainWindow();


    //add window to the scene
    scene->addWidget(window);

    //add window background
    QGraphicsPixmapItem * background = new QGraphicsPixmapItem();
    background->setPixmap(QPixmap(":/images/background"));


    //add background to the scene
    scene->addItem(background);








    // add a view to the scene
    QGraphicsView * view = new QGraphicsView(scene);

    view -> show();

    return a.exec();
}
