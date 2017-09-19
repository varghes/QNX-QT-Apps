#ifndef MYSCENE_H
#define MYSCENE_H

#endif // MYSCENE_H
#define Q_OBJECT
#include<QGraphicsScene>
//#include<QMediaPlayer>
#include<QMainWindow>
class MyScene:public QGraphicsScene{
Q_OBJECT
public:
   MyScene();
    //create sound object
   // QMediaPlayer * card_sound = new QMediaPlayer();
   // QMediaPlayer * win_sound = new QMediaPlayer();
   // QMediaPlayer * lose_sound = new QMediaPlayer();

    int desloc;

    bool first_time ;

    int player_sum ;

    int croupier_sum ;



public slots:
    //draw a new card
    void draw();
    // play sound when a new card is drawn
    void play_card_sound();
    // set the cards of the croupier
    void set_croupier_cards();
    //delete the scene
    void end_game();
    //star new round
    void clean_scene();


};
