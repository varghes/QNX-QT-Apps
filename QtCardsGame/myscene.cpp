#include<myscene.h>
#include <mypack.h>
#include <mybutton.h>


MyScene::MyScene()
{
	 first_time = true;

     player_sum = 0;

     croupier_sum = 0;
}
void MyScene::play_card_sound()
{

   // card_sound->setMedia(QUrl("qrc:/sounds/card.sound.wav"));
    //card_sound->play();

}



void MyScene::set_croupier_cards()
{
    //create croupier first card
    MyPack * croupier_first_card = new MyPack();
    croupier_first_card->card->setPos(200,300);
    addItem(croupier_first_card->card);
    //king, queen, and knave control
    if (croupier_first_card ->card_number == 11 || croupier_first_card ->card_number == 12 || croupier_first_card ->card_number == 13 ){
        croupier_sum +=10;
    }
    else{
    croupier_sum += croupier_first_card->card_number;
    }

    //create croupier second card
    MyPack * croupier_second_card = new MyPack();
    croupier_second_card->card->setPos(350,300);
    addItem(croupier_second_card->card);
    //king, queen, and knave control
    if (croupier_second_card ->card_number == 11 || croupier_second_card ->card_number == 12 || croupier_second_card ->card_number == 13 ){
        croupier_sum+=10;
    }
    else{
    croupier_sum += croupier_second_card->card_number;
    }

    //create croupier thrird card
    MyPack * croupier_third_card = new MyPack();
    croupier_third_card->card->setPos(500,300);


     //create the last possible card of the croupier
     MyPack * croupier_fourth_card = new MyPack();
     croupier_fourth_card->card->setPos(650,300);


    if (croupier_first_card->card_number + croupier_second_card->card_number < 17){

        //king, queen, and knave control
        if (croupier_third_card ->card_number == 11 || croupier_third_card ->card_number == 12 || croupier_third_card ->card_number == 13 ){
            croupier_sum +=10;
        }
        else{
        croupier_sum += croupier_third_card->card_number;
        }
        //add croupier third card
        addItem(croupier_third_card->card);}

       if (croupier_first_card->card_number + croupier_second_card->card_number + croupier_third_card->card_number < 17){

         //king, queen, and knave control
         if (croupier_fourth_card ->card_number == 11 || croupier_fourth_card ->card_number == 12 || croupier_fourth_card ->card_number == 13 ){
             croupier_sum +=10;
         }
         else{
         croupier_sum += croupier_fourth_card->card_number;
         }
         //add croupier fourth card
         addItem(croupier_fourth_card->card);}


     //set win sound
   //  win_sound->setMedia(QUrl("qrc:/sounds/win.sound.wav"));
     //set lose sound
   //  lose_sound->setMedia(QUrl("qrc:/sounds/lose.sound.wav"));
     //conditions for winnig or losing
     if ((player_sum <= 21 && croupier_sum <= 21 && player_sum > croupier_sum) || (player_sum <= 21 && croupier_sum > 21)){
   //      win_sound->play();
   ;
     }
     else{
 //        lose_sound->play();
 ;
 }
 


}



void MyScene::end_game()
{

this->clear();
delete this;

}

void MyScene::clean_scene()
{
    //variables inicialization
    desloc = 0;
    croupier_sum = 0;
    player_sum = 0;
    //recriate scene
    QGraphicsPixmapItem * background = new QGraphicsPixmapItem();

    background->setPixmap(QPixmap(":/images/background"));

    addItem(background);

    MyPack *mypack_card1 = new MyPack();
    mypack_card1->card->setPos(50,60);
    addItem(mypack_card1 ->card);
    if (mypack_card1->card_number == 11 || mypack_card1 ->card_number == 12 || mypack_card1 ->card_number == 13 ){
        player_sum +=10;
    }
    else{
    player_sum += mypack_card1->card_number;
    }

    MyPack *mypack_card2 = new MyPack();
    mypack_card2->card->setPos(200,60);
    addItem(mypack_card2->card);
    if (mypack_card2 ->card_number == 11 || mypack_card2 ->card_number == 12 || mypack_card2 ->card_number == 13 ){
        player_sum +=10;
    }
    else{
    player_sum += mypack_card2->card_number;
    }

    MyButton * draw = new MyButton();
    draw->setText("Draw");
    draw->setGeometry(40,1,100,50);
    addWidget(draw);


    QObject::connect(draw,SIGNAL(clicked()),this,SLOT(draw()));

    QObject::connect(draw,SIGNAL(clicked()),this,SLOT(play_card_sound()));

    MyButton * show_croupier = new MyButton();
    show_croupier->setText("Show croupier");
    show_croupier->setGeometry(200,1,200,50);

    addWidget(show_croupier);

    QObject::connect(show_croupier,SIGNAL(clicked()),this,SLOT(set_croupier_cards()));


    MyButton * end_game = new MyButton();
    end_game->setText("End game");
    end_game->setGeometry(590,1,100,50);

    addWidget(end_game);

    QObject::connect(end_game,SIGNAL(clicked()),this,SLOT(end_game()));


    MyButton * new_round = new MyButton();
    new_round->setText("New round");
    new_round->setGeometry(450,1,100,50);

    addWidget(new_round);

    QObject::connect(new_round,SIGNAL(clicked()),this,SLOT(clean_scene()));







}



void MyScene::draw()
{

   if (first_time){
       desloc = 150;}
   else{
       desloc = desloc + 150;}

    //choose a random card
    MyPack * random_card = new MyPack();
    random_card ->card->setPos(200 + desloc,60);
    player_sum += random_card->card_number;
    //add the card to the scene
    addItem(random_card->card);

    first_time = false;

}
