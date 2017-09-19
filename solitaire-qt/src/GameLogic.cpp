/**
 * Copyright (c) 2011-2014 Microsoft Mobile.
 */

#include "GameLogic.h"

#include <QTime>

#include "Card.h"
#include "CardDeck.h"


GameLogic::GameLogic(QObject *parent)
    : QObject(parent)
{
    // Create cards
    createCards();

    // Create seed for the random
    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());
}

GameLogic::~GameLogic()
{
    // Removes pointer from the array and deletes 
    // actual class
    while (!m_cards.isEmpty()) {
        delete m_cards[0];
        m_cards.removeAt(0);
    }

    while (!m_messedCards.isEmpty()) {
        delete m_messedCards[0];
        m_messedCards.removeAt(0);
    }
}

int GameLogic::randInt(int low, int high)
{
    // Get random number between low and high
    return qrand() % ((high + 1) - low) + low;
}

void GameLogic::messCards()
{
    while (!m_cards.isEmpty()) {
        int rand = randInt(0, m_cards.count() - 1);
        Card *card = m_cards[rand];
        m_messedCards.append(card);
        m_cards.removeAt(rand); // Does not delete the card instance but
                                // removes the pointer from the list.
    }
}

QList<Card*> GameLogic::messedCardList()
{
    return m_messedCards;
}

void GameLogic::createCards()
{
    m_cards.append(new Card(QString(":/images/clubs/Club_ace_75x110.svg"),1,Card::Club,Card::Black));
    m_cards.append(new Card(QString(":/images/clubs/Club_2_75x110.svg"),2,Card::Club,Card::Black));
    m_cards.append(new Card(QString(":/images/clubs/Club_3_75x110.svg"),3,Card::Club,Card::Black));
    m_cards.append(new Card(QString(":/images/clubs/Club_4_75x110.svg"),4,Card::Club,Card::Black));
    m_cards.append(new Card(QString(":/images/clubs/Club_5_75x110.svg"),5,Card::Club,Card::Black));
    m_cards.append(new Card(QString(":/images/clubs/Club_6_75x110.svg"),6,Card::Club,Card::Black));
    m_cards.append(new Card(QString(":/images/clubs/Club_7_75x110.svg"),7,Card::Club,Card::Black));
    m_cards.append(new Card(QString(":/images/clubs/Club_8_75x110.svg"),8,Card::Club,Card::Black));
    m_cards.append(new Card(QString(":/images/clubs/Club_9_75x110.svg"),9,Card::Club,Card::Black));
    m_cards.append(new Card(QString(":/images/clubs/Club_10_75x110.svg"),10,Card::Club,Card::Black));
    m_cards.append(new Card(QString(":/images/clubs/Club_jack_75x110.svg"),11,Card::Club,Card::Black));
    m_cards.append(new Card(QString(":/images/clubs/Club_queen_75x110.svg"),12,Card::Club,Card::Black));
    m_cards.append(new Card(QString(":/images/clubs/Club_king_75x110.svg"),13,Card::Club,Card::Black));

    m_cards.append(new Card(QString(":/images/diamond/Diamond_ace_75x110.svg"),1,Card::Diamond,Card::Red));
    m_cards.append(new Card(QString(":/images/diamond/Diamond_2_75x110.svg"),2,Card::Diamond,Card::Red));
    m_cards.append(new Card(QString(":/images/diamond/Diamond_3_75x110.svg"),3,Card::Diamond,Card::Red));
    m_cards.append(new Card(QString(":/images/diamond/Diamond_4_75x110.svg"),4,Card::Diamond,Card::Red));
    m_cards.append(new Card(QString(":/images/diamond/Diamond_5_75x110.svg"),5,Card::Diamond,Card::Red));
    m_cards.append(new Card(QString(":/images/diamond/Diamond_6_75x110.svg"),6,Card::Diamond,Card::Red));
    m_cards.append(new Card(QString(":/images/diamond/Diamond_7_75x110.svg"),7,Card::Diamond,Card::Red));
    m_cards.append(new Card(QString(":/images/diamond/Diamond_8_75x110.svg"),8,Card::Diamond,Card::Red));
    m_cards.append(new Card(QString(":/images/diamond/Diamond_9_75x110.svg"),9,Card::Diamond,Card::Red));
    m_cards.append(new Card(QString(":/images/diamond/Diamond_10_75x110.svg"),10,Card::Diamond,Card::Red));
    m_cards.append(new Card(QString(":/images/diamond/Diamond_jack_75x110.svg"),11,Card::Diamond,Card::Red));
    m_cards.append(new Card(QString(":/images/diamond/Diamond_queen_75x110.svg"),12,Card::Diamond,Card::Red));
    m_cards.append(new Card(QString(":/images/diamond/Diamond_king_75x110.svg"),13,Card::Diamond,Card::Red));
    
    m_cards.append(new Card(QString(":/images/heart/Heart_ace_75x110.svg"),1,Card::Heart,Card::Red));
    m_cards.append(new Card(QString(":/images/heart/Heart_2_75x110.svg"),2,Card::Heart,Card::Red));
    m_cards.append(new Card(QString(":/images/heart/Heart_3_75x110.svg"),3,Card::Heart,Card::Red));
    m_cards.append(new Card(QString(":/images/heart/Heart_4_75x110.svg"),4,Card::Heart,Card::Red));
    m_cards.append(new Card(QString(":/images/heart/Heart_5_75x110.svg"),5,Card::Heart,Card::Red));
    m_cards.append(new Card(QString(":/images/heart/Heart_6_75x110.svg"),6,Card::Heart,Card::Red));
    m_cards.append(new Card(QString(":/images/heart/Heart_7_75x110.svg"),7,Card::Heart,Card::Red));
    m_cards.append(new Card(QString(":/images/heart/Heart_8_75x110.svg"),8,Card::Heart,Card::Red));
    m_cards.append(new Card(QString(":/images/heart/Heart_9_75x110.svg"),9,Card::Heart,Card::Red));
    m_cards.append(new Card(QString(":/images/heart/Heart_10_75x110.svg"),10,Card::Heart,Card::Red));
    m_cards.append(new Card(QString(":/images/heart/Heart_jack_75x110.svg"),11,Card::Heart,Card::Red));
    m_cards.append(new Card(QString(":/images/heart/Heart_queen_75x110.svg"),12,Card::Heart,Card::Red));
    m_cards.append(new Card(QString(":/images/heart/Heart_king_75x110.svg"),13,Card::Heart,Card::Red));

    m_cards.append(new Card(QString(":/images/spade/Spade_ace_75x110.svg"),1,Card::Spade,Card::Black));
    m_cards.append(new Card(QString(":/images/spade/Spade_2_75x110.svg"),2,Card::Spade,Card::Black));
    m_cards.append(new Card(QString(":/images/spade/Spade_3_75x110.svg"),3,Card::Spade,Card::Black));
    m_cards.append(new Card(QString(":/images/spade/Spade_4_75x110.svg"),4,Card::Spade,Card::Black));
    m_cards.append(new Card(QString(":/images/spade/Spade_5_75x110.svg"),5,Card::Spade,Card::Black));
    m_cards.append(new Card(QString(":/images/spade/Spade_6_75x110.svg"),6,Card::Spade,Card::Black));
    m_cards.append(new Card(QString(":/images/spade/Spade_7_75x110.svg"),7,Card::Spade,Card::Black));
    m_cards.append(new Card(QString(":/images/spade/Spade_8_75x110.svg"),8,Card::Spade,Card::Black));
    m_cards.append(new Card(QString(":/images/spade/Spade_9_75x110.svg"),9,Card::Spade,Card::Black));
    m_cards.append(new Card(QString(":/images/spade/Spade_10_75x110.svg"),10,Card::Spade,Card::Black));
    m_cards.append(new Card(QString(":/images/spade/Spade_jack_75x110.svg"),11,Card::Spade,Card::Black));
    m_cards.append(new Card(QString(":/images/spade/Spade_queen_75x110.svg"),12,Card::Spade,Card::Black));
    m_cards.append(new Card(QString(":/images/spade/Spade_king_75x110.svg"),13,Card::Spade,Card::Black));
}

bool GameLogic::isValidMove(Card* topCard, BaseCardDeck* deck)
{
    if (deck->type() == BaseCardDeck::CardDeck) {
        // If there is no cards in the deck, then the first one must be King card
        if (deck->cards().count() == 0 && topCard->value() != 13) {
            return false;
        }
    }
    else if (deck->type() == BaseCardDeck::Foundation)  {
        // Ace card must be the first card in foundation
        if (deck->cards().count() == 0 && topCard->value() != 1) {
            return false;
        }
    }
    else {
        return false;
    }

    return true;
}

bool GameLogic::isValidMove(Card *topCard, Card *bottomCard)
{
    if (!topCard || !bottomCard) {
        return false;
    }

    // Moving cards between card decks
    if (bottomCard->deck()->type() == BaseCardDeck::CardDeck) {
        // Card decks must differ
        if (bottomCard->deck() == topCard->deck()) {
            return false;
        }

        // Card can be top of one step greater card and different color
        if (bottomCard->color() == topCard->color() || 
            topCard->value()+1 != bottomCard->value()) {
            return false;
        }
    }
    // Moving cards between card deck and foundation
    else if (bottomCard->deck()->type() == BaseCardDeck::Foundation) {
        // Card decks must differ
        if (bottomCard->deck() == topCard->deck()) {
            return false;
        }

        // Cards must be in ascending order and same suite
        if (topCard->value() != bottomCard->value() + 1 ||
            topCard->suite() != bottomCard->suite()) {
            return false;
        }
    }
    else {
        return false;
    }

    return true;
}

