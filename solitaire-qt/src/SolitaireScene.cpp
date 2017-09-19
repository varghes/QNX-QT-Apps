/**
 * Copyright (c) 2011-2014 Microsoft Mobile.
 */

#include "SolitaireScene.h"

#include <QDebug>
#include <QtGui>

#include "Card.h"
#include "CardDeck.h"
#include "Deck.h"
#include "GameLogic.h"


SolitaireScene::SolitaireScene(GameLogic *gameLogic, QObject *parent)
    : QGraphicsScene(parent),
      m_gameLogic(gameLogic),
      m_activeGraphicItem(0)
{
}

SolitaireScene::~SolitaireScene()
{
}

void SolitaireScene::createDecks()
{
    int zOrder(0);

    // Create data classes and the corresponding graphics view framework items.
    for (int i = 0; i < 7; ++i) {
        m_deck[i] = new CardDeck(BaseCardDeck::CardDeck, this);
        m_deckItem[i] = new Deck(Deck::CardDeck, m_deck[i]);
        m_deckItem[i]->setZValue(zOrder++);
        addItem(m_deckItem[i]);
    }

    for (int i = 0; i < 4; ++i) {
        m_foundation[i] = new CardDeck(BaseCardDeck::Foundation, this);
        m_foundationItem[i] = new Deck(Deck::Foundation, m_foundation[i]);
        m_foundationItem[i]->setZValue(zOrder++);
        addItem(m_foundationItem[i]);
    }

    m_stock = new CardDeck(BaseCardDeck::Stock, this);
    m_stockItem = new Deck(Deck::Stock, m_stock);
    addItem(m_stockItem);

    m_waste = new CardDeck(BaseCardDeck::Waste, this);
    m_wasteItem = new Deck(Deck::Waste, m_waste);
    addItem(m_wasteItem);
    
    // Create card items to each deck.

    // Get all messed cards
    QList<Card*> cards = m_gameLogic->messedCardList();
    Card *childCard(0);

    for (int deck = 0; deck < 7; ++deck) {
        for (int i = 0; i < deck + 1; i++) {
            Card *card = cards.first();
            card->setZValue(zOrder++);
            card->setDeck(m_deck[deck]);

            if (childCard) {
                childCard->setParentCard(card);
                card->setChildCard(childCard);
            }

            addItem(card);
            cards.removeFirst();
            childCard = card;
        }

        childCard->setCardVisibility(true);
        childCard = 0;
    }

    // Deal rest of the cards into the stock deck.
    while (!cards.isEmpty()) {
        Card *card = cards.first();
        card->setZValue(zOrder++);
        card->setCardVisibility(false);
        card->setDeck(m_stock);
        addItem(card);
        cards.removeFirst();
    }
}
    
qreal SolitaireScene::deckCap()
{
    return CARD_WIDTH / 8.0;
}

void SolitaireScene::updatePositions(const QRectF& rect)
{
    // Calculate 7 decks positions
    qreal deckX(0);
    qreal deckY(0);
    qreal deckCapVal = deckCap();

    if (rect.width() > rect.height()) {
        // Terminal landscape
        deckY = rect.height() / 3;
        deckX = (rect.width() - (8 * CARD_WIDTH + 8 * deckCapVal)) / 2;

#ifdef Q_OS_SYMBIAN
        // -20 is some extra space for exit btn in Symbian
        deckX -= 20;
#endif
    }
    else {
        // Terminal portrait
        deckY = rect.height() / 2 - CARD_HEIGHT;
        deckX = (rect.width() - (8 * CARD_WIDTH + 8 * deckCapVal)) / 2;
    }

    deckX += deckCapVal + CARD_WIDTH / 2;
    Card *card(0);
    int counter(0);

    for (int deck = 0; deck < 7; ++deck) {
        m_deckItem[deck]->setPos(deckX, deckY);

        if (deck == 0) {
            m_stockItem->setPos(deckX, deckY - (CARD_HEIGHT + deckCapVal));
        }
        else if (deck == 1) {
            m_wasteItem->setPos(deckX, deckY - (CARD_HEIGHT + deckCapVal));
        }

        if (deck >= 3) {
            m_foundationItem[deck - 3]->setPos(deckX, deckY - (CARD_HEIGHT + deckCapVal));
        }

        foreach (card, m_deck[deck]->cards()) {
            card->setPos(QPointF(deckX, deckY + CARD_TOP_CAP * counter));
            counter++;
        }
    
        deckX += deckCapVal + CARD_WIDTH;
        counter = 0;
    }

    // Update cards in stock
    foreach (card, m_stock->cards()) {
        card->setPos(m_stockItem->pos());
    }

    // Update cards in waste
    foreach (card, m_waste->cards()) {
        card->setPos(m_wasteItem->pos());
    }
    
    // Update foundation cards
    for (int i = 0; i < 4; ++i) {
        foreach (card, m_foundation[i]->cards()) {
            card->setPos(m_foundationItem[i]->pos());
        }
    }
}

void SolitaireScene::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    // Check that is mouseReleaseEvent occured on previous mouse event 
    if (m_activeGraphicItem) {
        if (m_activeGraphicItem->type() == Card::CardType)
        {
            Card* losedCard = static_cast<Card*>(m_activeGraphicItem);
            losedCard->cancelCardMove();
            losedCard->update();
        }

        m_activeGraphicItem = 0;
    }
    else {
        // Store selected graphicitem
        m_activeGraphicItem = itemAt(mouseEvent->scenePos());
    }

    // Sends mouse events into graphics items
    QGraphicsScene::mousePressEvent(mouseEvent);
}

void SolitaireScene::mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    if (m_activeGraphicItem)
        QGraphicsScene::mouseMoveEvent(mouseEvent);
}

void SolitaireScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    QGraphicsScene::mouseReleaseEvent(mouseEvent);
    
    if (m_activeGraphicItem && m_activeGraphicItem->type() == Card::CardType) {
        // Moving / pointing cards
        Card *activeCard = static_cast<Card*>(m_activeGraphicItem);
        int error = 0;
        if (activeCard->deck()->type() == BaseCardDeck::CardDeck ||
            activeCard->deck()->type() == BaseCardDeck::Waste)
        {
            // Dragging cards into card decks or foundation
            QList<QGraphicsItem*> items = collidingItems(m_activeGraphicItem);
            // Do some pre-cleaning for the colliding items
            cleanItems(items);

            // Colliding items?
            if (!items.isEmpty())
            {
                // Try to handle card moves between decks
                error = handleCardMoves(items);
                items.clear();
            }
            else
            {
                // Cancel card move, there was nothing under it
                error = -1;
            }
        }
        else if (activeCard->deck()->type() == BaseCardDeck::Stock) {
            // Getting new cards from stock to waste
            activeCard->setDeck(m_waste);
            activeCard->setCardVisibility(true);
            activeCard->setPos(m_wasteItem->pos());
            activeCard->setCarToTop();
            activeCard->update();
        }
        else {
            error = -1;
        }

        if (error) {
            // Cancel card move, there was nothing under it
            activeCard->cancelCardMove();
            activeCard->update();
            update();
        }
    }
    else if (m_activeGraphicItem && m_activeGraphicItem->type() == Deck::Stock) {
        // Pointing empty Stock deck
        // Stock is empty, copy cards from waste back to stock
        Card* card(0);

        while (!m_waste->cards().isEmpty()) {
            card = m_waste->cards().first();
            card->setDeck(m_stock);
            card->setCardVisibility(false);
            card->setPos(m_stockItem->pos());
            card->update();
        }

        if (card) {
            card->setCardVisibility(true);
            card->setDeck(m_waste);
            card->setPos(m_wasteItem->pos());
            card->setCarToTop();
            card->update();
        }
    }

    // Reset active graphic iten
    m_activeGraphicItem = 0;
}

void SolitaireScene::cleanItems(QList<QGraphicsItem*> &items)
{
    // List must has items that really collides with dragging items,
    // not also these actual dragging items etc.

    QGraphicsItem *collidingItem(0);
    int i(0);

    foreach (collidingItem, items) {
        // Card graphic item
        if (collidingItem->type() == Card::CardType) {
            Card *collidingCard = static_cast<Card*>(collidingItem);

            // Remove items that user is dragging
            if (collidingItem->zValue() >= m_activeGraphicItem->zValue()) {
                items.removeAt(i);
                i--;
            }
            // If colliding card does not belong card deck or foundation, remove it
            else if (collidingCard->deck()->type() != BaseCardDeck::CardDeck &&
                     collidingCard->deck()->type() != BaseCardDeck::Foundation)
            {
                items.removeAt(i);
                i--;
            }
        }
        // Deck graphic item
        else if (collidingItem->type() == Deck::CardDeck) {
            // Do not remove this colliding item
        }
        // Deck graphic item
        else if (collidingItem->type() == Deck::Foundation) {
            // Do not remove this colliding item
        }
        else {
            items.removeAt(i);
            i--;
        }

        i++;
    }
}

int SolitaireScene::handleCardMoves(QList<QGraphicsItem*> &items)
{
    int error(-1);
    QGraphicsItem *item(0);

    foreach (item, items) {
        // Card is moving top of another card
        if (item->type() == Card::CardType) {
            Card* bottomCard = static_cast<Card*>(item);
            Card* topCard = static_cast<Card*>(m_activeGraphicItem);
    
            // Bottom card can not have parent yet, if it
            // has we cannot put new card on it
            if (bottomCard->parentCard()) {
                continue;
            }
    
            // Can add one card at the time into foundation decks
            if (topCard->parentCard() &&
                bottomCard->deck()->type() == BaseCardDeck::Foundation) {
                continue;
            }
            // Can not move items from other decks than card deck or waste
            if (topCard->deck()->type() != BaseCardDeck::CardDeck &&
                topCard->deck()->type() != BaseCardDeck::Waste) {
                break;
            }
    
            if (!topCard->isCardFaceVisible()) {
                break;
            }
    
            // Check move validity
            if (m_gameLogic->isValidMove(topCard,bottomCard))
            {
                // Card move accepted, do move
                // NOTE: These changes affec also to topCard parent cards
                // when moving multiple cards
    
                // Change card deck to new one
                topCard->setDeck(bottomCard->deck());
    
                // Set new position
                QPointF pos = bottomCard->pos();

                if (topCard->deck()->type() == BaseCardDeck::Foundation) {
                    topCard->setPos(QPointF(pos.x(),pos.y()));
                }
                else {
                    topCard->setPos(QPointF(pos.x(),pos.y()+CARD_TOP_CAP));
                    // Move parent (upper) cards also if you are not top card
                    topCard->childPosChanged(topCard->pos());
                }
    
                // Set child card visibility and
                // parent to zero values for card under moving
                if (topCard->childCard()) {
                    topCard->childCard()->setCardVisibility(true);
                    topCard->childCard()->setParentCard(0);
                    topCard->childCard()->update();
                    topCard->storeDefaultPos();
                }
    
                // Set new parent / child realationship
                bottomCard->setParentCard(topCard);
                topCard->setChildCard(bottomCard);
    
                bottomCard->update();
                topCard->update();
    
                // Valid move done, no errors send
                error = 0;
                break;
            }
        }
        // Card is moving top of (empty) deck
        else if (item->type() == Deck::CardDeck) {
            Deck *activeDeck = static_cast<Deck*>(item);
            Card *card = static_cast<Card*>(m_activeGraphicItem);
    
            // Can not move items from other decks than card deck or waste
            if (card->deck()->type() != BaseCardDeck::CardDeck &&
                card->deck()->type() != BaseCardDeck::Waste) {
                break;
            }
    
            // Can not move card that face is not visible
            if (!card->isCardFaceVisible()) {
                break;
            }
            
            // Can not add card to this level if it already has 
            // other cards. Insertion must go to card level.
            if (activeDeck->deck()->cards().count() > 0) {
                continue;
            }
            
            if (m_gameLogic->isValidMove(card, activeDeck->deck())) {
                // Card is moving on top of new deck
    
                // Change card deck to new one
                card->setDeck(activeDeck->deck());
    
                // Set child card visibility and
                // parent to zero values for card under moving
                if (card->childCard()) {
                    card->childCard()->setCardVisibility(true);
                    card->childCard()->setParentCard(0);
                    card->childCard()->update();
                    card->setChildCard(0);
                }
    
                // Set card new position
                card->setPos(activeDeck->pos());

                // Move parent (upper) cards also if you are not top card
                card->childPosChanged(card->pos());
                
                card->storeDefaultPos();
                
                card->update();
                error = 0;
                break;
            }
        }
        // Card is moving top of (empty) foundation
        else if (item->type() == Deck::Foundation) {
            Deck *activeDeck = static_cast<Deck*>(item);
            Card *card = static_cast<Card*>(m_activeGraphicItem);
    
            // Card can not have parent, we can set
            // one car in the same time to the new deck
            if (card->parentCard()) {
                break;
            }
              
            // Can not move card that face is not visible
            if (!card->isCardFaceVisible()) {
                break;
            }
            
            // Can not move items from other decks than card deck or waste
            if (card->deck()->type() != BaseCardDeck::CardDeck &&
                card->deck()->type() != BaseCardDeck::Waste) {
                break;
            }
    
            // Can not add card to this level if it already has 
            // other cards. Insertion must go to card level.
            if (activeDeck->deck()->cards().count() > 0) {
                continue;
            }
            
            if (m_gameLogic->isValidMove(card,activeDeck->deck())) {
                // Card is moving on top of new deck
    
                // Change card deck to new one
                card->setDeck(activeDeck->deck());
    
                // Set child card visibility and
                // parent to zero values for card under moving
                if (card->childCard())
                {
                    card->childCard()->setCardVisibility(true);
                    card->childCard()->setParentCard(0);
                    card->childCard()->update();
                    card->setChildCard(0);
                }
    
                // Remove parent
                card->setParentCard(0);
    
                // Set card new position
                card->setPos(activeDeck->pos());
    
                card->update();
                error = 0;
                break;
            }
        }
    } // foreach
    
    return error;
}

qreal SolitaireScene::getItemsTopMostZOrder()
{
    qreal z = 0;
    QGraphicsItem* item = 0;

    foreach (item, items()) {
        if (item->zValue() > z) {
            z = item->zValue();
        }
    }
    return z;
}

