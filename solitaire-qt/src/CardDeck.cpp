/**
 * Copyright (c) 2011-2014 Microsoft Mobile.
 */

#include "CardDeck.h"
#include <QSvgRenderer>
#include "Card.h"


// BaseCardDeck ---------------------------------------------------------------

BaseCardDeck::BaseCardDeck(BaseCardDeck::DeckType type, QObject *parent)
    : QObject(parent),
      m_svgRenderer(0),
      m_deckType(type)
{
    // Common place for the cards to get background
    m_svgRenderer = new QSvgRenderer(this);
    m_svgRenderer->load(QString(":/images/card_background_75x110.svg"));
}

BaseCardDeck::~BaseCardDeck()
{
    // Clear items, do not delete these because GameLogic class owns them.
    m_cards.clear();
}

void BaseCardDeck::addCard(Card *newCard)
{
    m_cards.append(newCard);
}

void BaseCardDeck::removeCard(Card *card)
{
    Card *item = 0;
    int i = 0;

    foreach (item, m_cards) {
        if (item == card) {
            // Does not delete the card object, only removes pointer from the
            // list.
            m_cards.removeAt(i);
            break;
        }

        i++;
    }
}

QList<Card*> BaseCardDeck::cards()
{
    return m_cards;
}


// CardDeck -------------------------------------------------------------------

CardDeck::CardDeck(BaseCardDeck::DeckType type, QObject *parent)
    : BaseCardDeck(type, parent)
{
}

CardDeck::~CardDeck()
{
}

