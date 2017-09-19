#include<mypack.h>

int MyPack::rand_suit()
{
    int random = rand()%(4-1 + 1) + 1;
    return random;
}

int MyPack::rand_card()
{
    int random = rand()%(13-1 + 1) + 1;
    return random;
}
MyPack::MyPack()
{
	// random generation function for the card suit
 suit = rand_suit();
// random generation function for the card number

 card_number = rand_card();
 str = QString(":/images/") + QString::number(rand_suit()) + QString(".") + QString::number(card_number) + QString(".png");


//create a card according to the randon numbers rand_suit and rand_card
card = new MyCard(QPixmap(str));
}



