/**
 * Copyright (c) 2011 Nokia Corporation.
 */

#ifndef SOLITAIRESCENE_H
#define SOLITAIRESCENE_H

#include <QGraphicsScene>

// Forward declarations
class CardDeck;
class Deck;
class GameLogic;
class QGraphicsSceneMouseEvent;

// Constants
const qreal CARD_WIDTH(75.0);
const qreal CARD_HEIGHT(110.0);
const qreal CARD_TOP_CAP(20);


class SolitaireScene : public QGraphicsScene
{
    Q_OBJECT
    
public:
    SolitaireScene(GameLogic* gameLogic, QObject *parent = 0);
    ~SolitaireScene();

private:
    void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent);

    int handleCardMoves(QList<QGraphicsItem*> &items);
    void cleanItems(QList<QGraphicsItem*> &items);
        
public slots:
    void updatePositions(const QRectF& rect);
        
public:
    void createDecks();
    qreal getItemsTopMostZOrder();
    qreal deckCap();

private: // Data
    // Game engine
    GameLogic *m_gameLogic;

    // Data classes
    CardDeck *m_deck[7];
    CardDeck *m_foundation[4];
    CardDeck *m_stock;
    CardDeck *m_waste;

    // Graphic item classes
    QGraphicsItem *m_activeGraphicItem;
    Deck *m_deckItem[7];
    Deck *m_foundationItem[4];
    Deck *m_stockItem;
    Deck *m_wasteItem;
};

#endif // SOLITAIRESCENE_H
