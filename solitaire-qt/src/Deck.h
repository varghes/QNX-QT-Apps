/**
 * Copyright (c) 2011 Nokia Corporation.
 */

#ifndef DECK_H
#define DECK_H

#include <QGraphicsSvgItem>

// Forward declarations
class BaseCardDeck;
class QGraphicsItem;
class QGraphicsScene;


class Deck : public QGraphicsSvgItem
{
    Q_OBJECT

public:
    // Card deck type
    enum DeckType {
        CardDeck = UserType + 2,
        Foundation = UserType + 3,
        Stock = UserType + 4,
        Waste = UserType + 5
    };

public: // Constructor and destructor
    Deck(DeckType deckType,
         BaseCardDeck *deck = 0,
         QGraphicsItem *parentItem = 0);
    ~Deck();
    
public:
    int type() const;
    QPainterPath shape() const;
    QRectF boundingRect() const;
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget = 0);
    BaseCardDeck *deck() { return m_deckData; }

private: // Data
    BaseCardDeck *m_deckData;
    DeckType m_deckType;
};

#endif // DECK_H
