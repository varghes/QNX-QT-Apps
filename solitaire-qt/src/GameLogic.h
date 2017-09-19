/**
 * Copyright (c) 2011 Nokia Corporation.
 */

#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include <QList>
#include <QObject>
#include <QString>

// Forward declarations
class BaseCardDeck;
class Card;


class GameLogic : public QObject
{
    Q_OBJECT
    
public:
    GameLogic(QObject *parent = 0);
    ~GameLogic();

public:
    int randInt(int low, int high);
    void messCards();
    QList<Card*> messedCardList();
    bool isValidMove(Card* topCard, BaseCardDeck* deck);
    bool isValidMove(Card* topCard, Card* bottomCard);

private:
    void createCards();

private: // Data
    QList<Card*> m_cards; // Owned
    QList<Card*> m_messedCards; // Owned
};

#endif //GAMELOGIC_H
