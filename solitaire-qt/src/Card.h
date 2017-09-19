/**
 * Copyright (c) 2011 Nokia Corporation.
 */

#ifndef CARD_H
#define CARD_H

#include <QGraphicsSvgItem>

// Forward declarations
class BaseCardDeck;
class QGraphicsItem;
class QGraphicsScene;


class Card : public QGraphicsSvgItem
{
    Q_OBJECT
    
public:
    enum { CardType = UserType + 1 };

    // Card suite enum
    enum CardSuite {
        Club = 1,
        Diamond,
        Heart,
        Spade
    };

    // Card color enum
    enum CardColor {
        Red = 1,
        Black
    };

public: // Constructor and destructor.
    Card(const QString &fileName, int value, CardSuite suite, CardColor color,
         BaseCardDeck* deck = 0, QGraphicsItem *parentItem = 0);
    ~Card();

public:
    int type() const;

    void setPos(const QPointF &pos);
    void setZValue(qreal z);

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void cancelCardMove();

    QPainterPath shape() const;
    QRectF boundingRect() const;

    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget = 0);
    QString svgPath() { return this->m_cardSvgPath; }
    CardSuite suite() { return this->m_cardSuite; }
    CardColor color() { return this->m_cardColor; }
    int value() { return this->m_cardValue; }
    BaseCardDeck *deck() { return this->m_cardDeck; }
    void setDeck(BaseCardDeck *deck);

    void setParentCard(Card *parent) { this->m_parentCard = parent; }
    Card* parentCard() { return this->m_parentCard; }

    void setChildCard(Card *child) { this->m_childCard = child; }
    Card *childCard() { return this->m_childCard; }
    void childPosChanged(QPointF parentPos);

    void setCardVisibility(bool visible);
    bool isCardFaceVisible() { return this->m_cardFaceVisible; }
    void setCarToTop();
    void storeDefaultPos();

private:
    void zOrderUpdate(qreal topZ);
    void cancelZorderUpdate();
        
private: // Data
    QPointF m_pointerPos;
    QPointF m_defaultPos;
    CardSuite m_cardSuite;
    int m_cardValue;
    CardColor m_cardColor;
    BaseCardDeck *m_cardDeck; // Not owned
    qreal m_prevZ;
    QString m_cardSvgPath;
    Card *m_parentCard; // Card on top of this car in the deck, not owned
    Card *m_childCard; // Card under this in the deck, not owned
    bool m_cardFaceVisible;
};

#endif // CARD_H
