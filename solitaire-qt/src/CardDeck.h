/**
 * Copyright (c) 2011 Nokia Corporation.
 */

#ifndef CARDDECK_H
#define CARDDECK_H

#include <QList>
#include <QObject>

// Forward declarations
class Card;
class QSvgRenderer;


class BaseCardDeck : public QObject
{
    Q_OBJECT
    
public:
    // Card deck type
    enum DeckType {
        CardDeck,
        Foundation,
        Stock,
        Waste
    };

public:
    BaseCardDeck(BaseCardDeck::DeckType type, QObject *parent = 0);
    ~BaseCardDeck();

public:
    void addCard(Card* newCard);
    void removeCard(Card* card);
    QList<Card*> cards();
    DeckType type() { return m_deckType; }

public: // Data
    QSvgRenderer *m_svgRenderer;
    
protected: // Data
    QList<Card*> m_cards; // Content not owned
    DeckType m_deckType;
};
    

class CardDeck : public BaseCardDeck
{
    Q_OBJECT
    
public:
    CardDeck(BaseCardDeck::DeckType type, QObject *parent = 0);
    ~CardDeck();
};


#endif //CARDDECK_H
