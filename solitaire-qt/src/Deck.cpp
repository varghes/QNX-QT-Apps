/**
 * Copyright (c) 2011-2014 Microsoft Mobile.
 */

#include "Deck.h"

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsSvgItem>
#include <QList>
#include <QPainter>
#include <QSvgRenderer>

#include "CardDeck.h"
#include "SolitaireScene.h"


Deck::Deck(DeckType deckType,
           BaseCardDeck *deck,
           QGraphicsItem *parentItem)
    : QGraphicsSvgItem(parentItem),
      m_deckData(deck),
      m_deckType(deckType)
{
}

Deck::~Deck()
{
}

int Deck::type() const
{
    // Enable the use of qgraphicsitem_cast with this item
    return m_deckType;
}

QPainterPath Deck::shape() const
{
    // This is called when finding collinding items
    // with QGraphicScene::collidingItems()
    QPainterPath path;
    QRectF rect = boundingRect();
    path.addRect(rect);
    return path;
}

QRectF Deck::boundingRect() const
{
    return QRectF(0, 0, CARD_WIDTH, CARD_HEIGHT);
}

void Deck::paint(QPainter *painter,
                 const QStyleOptionGraphicsItem *option,
                 QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    // Draw deck background rect
    painter->setPen(Qt::SolidLine);
    painter->setPen(QColor(Qt::black));
    QRectF rect = boundingRect();
    rect.adjust(4,4,-4,-4);
    
    painter->drawRoundedRect(rect,2,2);
}
