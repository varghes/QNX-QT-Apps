#ifndef MYPACK_H
#define MYPACK_H

#endif // MYPACK_H
#include<mycard.h>
#define Q_OBJECT
#include<QtAlgorithms>

class MyPack{
public:
MyPack();
// random generation function for the card suit
int  rand_suit();
//int suit = rand_suit();
int suit ;
// random generation function for the card number
int  rand_card();

int card_number;// = rand_card();
QString str;// = QString(":/images/") + QString::number(rand_suit()) + QString(".") + QString::number(card_number) + QString(".png");


//create a card according to the randon numbers rand_suit and rand_card
MyCard * card ;//= new MyCard(QPixmap(str));





};
