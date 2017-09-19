#include <myscene.h>
#include <QApplication>
#include <QGraphicsView>
#include <mybutton.h>
#include <mycard.h>
#include <QMainWindow>
#include <mypack.h>
#include <time.h>
#include <iostream>
#include<QObject>


using namespace std;




int main(int argc, char *argv[])
{


    QApplication a(argc, argv);





    //initialize random seed
    srand(time(NULL));

    // create a scene
    MyScene * scene = new MyScene();


    //create main window
    QMainWindow * window = new QMainWindow();

    //add window to the scene
    scene->addWidget(window);

    //add window background
    QGraphicsPixmapItem * background = new QGraphicsPixmapItem();

    background->setPixmap(QPixmap(":/images/background"));

    //add background to the scene
    scene->addItem(background);

    //add two firts cards to the scene

    MyPack *mypack_card1 = new MyPack();
    mypack_card1->card->setPos(50,60);
    scene->addItem(mypack_card1 ->card);
    //king, queen, and knave control
    if (mypack_card1 ->card_number == 11 || mypack_card1 ->card_number == 12 || mypack_card1 ->card_number == 13 ){
        scene->player_sum +=10;
    }
    else{
    scene->player_sum += mypack_card1->card_number;
    }

    MyPack *mypack_card2 = new MyPack();
    mypack_card2->card->setPos(200,60);
    scene->addItem(mypack_card2->card);
    //king, queen, and knave control
    if (mypack_card2 ->card_number == 11 || mypack_card2 ->card_number == 12 || mypack_card2 ->card_number == 13 ){
        scene->player_sum +=10;
    }
    else{
    scene->player_sum += mypack_card2->card_number;
    }



    //create button "draw"
    MyButton * draw = new MyButton();
    draw->setText("Draw");
    draw->setGeometry(40,1,100,50);

    //add button to the scene
    scene->addWidget(draw);

    //connect MyButton draw signal clicked to MyScene scene slot draw()
    QObject::connect(draw,SIGNAL(clicked()),scene,SLOT(draw()));
    //connect MyButton draw signal clicked to MyScene scene slot play_()
    QObject::connect(draw,SIGNAL(clicked()),scene,SLOT(play_card_sound()));


    //create buttom "show croupier"
    MyButton * show_croupier = new MyButton();
    show_croupier->setText("Show croupier");
    show_croupier->setGeometry(200,1,200,50);
    //add button to the scene
    scene->addWidget(show_croupier);
    //connect MyButton show croupier signal clicked to MyScene slot draw()
    QObject::connect(show_croupier,SIGNAL(clicked()),scene,SLOT(set_croupier_cards()));

    //create button "end game"
    MyButton * end_game = new MyButton();
    end_game->setText("End game");
    end_game->setGeometry(590,1,100,50);
    //add butoon to the scene
    scene->addWidget(end_game);
    //connect MyButton new round signal clicked to MyScene slot clean_scene()
    QObject::connect(end_game,SIGNAL(clicked()),scene,SLOT(end_game()));

    //crate button new round
    MyButton * new_round = new MyButton();
    new_round->setText("New round");
    new_round->setGeometry(450,1,100,50);
    //add button to the scene
    scene->addWidget(new_round);

    QObject::connect(new_round,SIGNAL(clicked()),scene,SLOT(clean_scene()));






    // add a view to the scene
    QGraphicsView * view = new QGraphicsView(scene);



    view -> show();
    return a.exec();
}
