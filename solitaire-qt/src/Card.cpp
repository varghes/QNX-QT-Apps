/**
 * Copyright (c) 2011-2014 Microsoft Mobile.
 */

#include "Card.h"

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsSvgItem>
#include <QList>
#include <QPainter>
#include <QSvgRenderer>

#include "CardDeck.h"
#include "SolitaireScene.h"


Card::Card(const QString &fileName, int value, CardSuite suite,
           CardColor color, BaseCardDeck *deck, QGraphicsItem *parentItem)
    : QGraphicsSvgItem(fileName,parentItem),
      m_cardSuite(suite),
      m_cardValue(value),
      m_cardColor(color),
      m_cardDeck(deck),
      m_cardSvgPath(fileName),
      m_parentCard(0),
      m_childCard(0),
      m_cardFaceVisible(false)
{
    setFlag(ItemIsSelectable);
    setFlag(ItemIsMovable);
    setCacheMode(DeviceCoordinateCache);
}

Card::~Card()
{
}

int Card::type() const
{
    // Enable the use of qgraphicsitem_cast with this item
    return CardType;
}

void Card::setPos(const QPointF &pos)
{
    QGraphicsItem::setPos(pos);
    m_defaultPos = this->pos();
}

void Card::storeDefaultPos()
{
    m_defaultPos = pos();

    if (m_parentCard) {
        m_parentCard->storeDefaultPos();
    }
}

void Card::setDeck(BaseCardDeck* deck)
{
    // Remove from old deck
    if (m_cardDeck) {
        m_cardDeck->removeCard(this);
    }

    // Change pointer
    m_cardDeck = deck;

    // Add to new deck
    m_cardDeck->addCard(this);

    // Set same deck for parent of this card
    if (m_parentCard) {
        m_parentCard->setDeck(m_cardDeck);
    }
}

void Card::setCardVisibility(bool visible)
{
    // Is card face or background shown
    m_cardFaceVisible = visible;
}

QPainterPath Card::shape() const
{
    // This is called when finding collinding items
    // with QGraphicScene::collidingItems()
    QPainterPath path;
    QRectF rect = boundingRect();
    path.addRect(rect);
    return path;
}

QRectF Card::boundingRect() const
{
    return QRectF(0, 0, CARD_WIDTH, CARD_HEIGHT);
}

void Card::paint(QPainter *painter,
                 const QStyleOptionGraphicsItem *option,
                 QWidget *widget)
{
    if (m_cardFaceVisible) {
        // Draw svg card face
        QGraphicsSvgItem::paint(painter, option, widget);
    }
    else {
        // Draw card background
        m_cardDeck->m_svgRenderer->render(painter,boundingRect());
        // NOTE: Do not call base class impl because it will then draw this
        // QGraphicsSvgItem's svg card face image
    }
}

void Card::setZValue(qreal z)
{
    QGraphicsItem::setZValue(z);
    m_prevZ = zValue();
}

void Card::setCarToTop()
{
    // Get top most item z order value
    SolitaireScene* scene = qobject_cast<SolitaireScene*>(this->scene());
    qreal z = scene->getItemsTopMostZOrder();

    // Set this card to top of others
    z += 0.1;
    setZValue(z);
    
    // Update parent (upper) cards z orders
    if (m_parentCard) {
        m_parentCard->zOrderUpdate(z);
    }
}

void Card::cancelZorderUpdate()
{
    setZValue(m_prevZ);

    // Cancel parent (upper) cards z orders
    if (m_parentCard) {
        m_parentCard->cancelZorderUpdate();
    }
}

void Card::zOrderUpdate(qreal topZ)
{
    topZ += 0.1;
    m_prevZ = zValue();
    setZValue(topZ);

    // Update parent (upper) cards z orders
    if (m_parentCard) {
        m_parentCard->zOrderUpdate(topZ);
    }
}

void Card::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (m_cardFaceVisible) {
        storeDefaultPos();
        m_pointerPos = event->scenePos();
        setCarToTop();
    }
}

void Card::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    // Allow move visible items that belongs card deck or waste
    if (m_cardFaceVisible &&
            (m_cardDeck->type() == BaseCardDeck::CardDeck ||
             m_cardDeck->type() == BaseCardDeck::Waste))
    {
        QPointF currPointerPos = event->scenePos();
        QPointF offset;
        offset.setX(currPointerPos.x() - m_pointerPos.x());
        offset.setY(currPointerPos.y() - m_pointerPos.y());
        moveBy(offset.x(),offset.y());
        m_pointerPos = currPointerPos;

        // Move parent (upper) cards also if you are not top card
        if (m_parentCard) {
            m_parentCard->childPosChanged(pos());
        }
    }
}

void Card::mouseReleaseEvent(QGraphicsSceneMouseEvent*)
{
    if (m_cardFaceVisible &&
            (m_cardDeck->type() == BaseCardDeck::CardDeck ||
             m_cardDeck->type() == BaseCardDeck::Waste))
    {
        if (m_parentCard) {
            m_parentCard->childPosChanged(pos());
        }
    }
}

void Card::childPosChanged(QPointF parentPos)
{
    QPointF myPoss = pos();

    if (parentPos != myPoss) {
        QPointF offset;
        offset.setX(parentPos.x() - myPoss.x());
        offset.setY(parentPos.y() - myPoss.y());
        moveBy(offset.x(),offset.y() + CARD_TOP_CAP);
    }

    // Move parent (upper) cards also if you are not top card
    if (m_parentCard) {
        m_parentCard->childPosChanged(pos());
    }
}

void Card::cancelCardMove()
{
    setPos(m_defaultPos);
    
    // Move parent (upper) cards also if you are not top card
    if (m_parentCard) {
        m_parentCard->cancelCardMove();
    }
    
    // Cancel z order update
    cancelZorderUpdate();
    update();
}
