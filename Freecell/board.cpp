/*
 * This file is part of Freecell.
 *
 * Freecell is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * Freecell is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Freecell.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "board.h"
#include "cardwidget.h"
#include "cardproxy.h"
#include "columnspot.h"
#include "acespot.h"
#include "freecell.h"
#include "boardscene.h"

#include <QGraphicsView>
#include <QGraphicsItem>
#include <QPointF>

Board::Board() : QObject()
{
    int i;

    for (i = 0; i < NB_COLUMNS; i++) {
        mLeafColumns[i] = 0;
    }

    mSelectedCard = 0;

    mBoardWidget = new QGraphicsView();
    mBoardWidget->setStyleSheet("background-color:green;");

    mScene = new BoardScene(QRectF(0, - (int)(CardWidget::HEIGHT * 1.2), 1200, 700), mBoardWidget);
    mBoardWidget->setScene(mScene);
    QObject::connect(mScene, SIGNAL(rightClick()), this, SLOT(tryAutomaticAceMove()));

    Freecell* freecell;
    for (i = 0; i < 4; i++) {
        freecell = new Freecell(this);
        freecell->setPosition(QPointF(i * CardWidget::WIDTH, mScene->sceneRect().y()));
        mFreeCells.push_back(freecell);
    }

    AceSpot* aceSpot;
    for (i = 0; i < 4; i++) {
        aceSpot = new AceSpot(this);
        aceSpot->setPosition(QPointF((4.5+i) * CardWidget::WIDTH, mScene->sceneRect().y()));
        mAceSpots.push_back(aceSpot);
    }

    ColumnSpot* columnSpot;
    for (i = 0; i < NB_COLUMNS; i++) {
        columnSpot = new ColumnSpot(this);
        columnSpot->setPosition(QPointF(i * CardWidget::WIDTH, 0));
        mColumns[i] = columnSpot;
    }

    mDeck = new Deck(this);
}

QWidget* Board::getBoardWidget()
{
    return mBoardWidget;
}

void Board::addItem(QGraphicsProxyWidget *proxy)
{
    mScene->addItem(proxy);
}

void Board::dealCards()
{
    Card* card;
    int i = 0, col = 0;

    mDeck->shuffle();
    while (mDeck->getSize()) {
        card = mDeck->drawCard();
        QPoint pos((i % NB_COLUMNS) * CardWidget::WIDTH, (i / NB_COLUMNS) * CardWidget::HEIGHT / 8);
        card->setPosition(pos);
        card->setParent(mLeafColumns[col]);
        card->setOnAceSpot(false);
        mLeafColumns[col] = card;

        // first line
        if (i / NB_COLUMNS == 0) {
            card->setParent(mColumns[i]);
        }
        col = ++i % NB_COLUMNS;

        mCards.push_back(card);
        card->show();
    }
}

void Board::collectCards()
{
    Card* card;

    for (int i = 0; i < NB_COLUMNS; i++) {
        mLeafColumns[i] = 0;
    }

    while (mCards.size()) {
        card = mCards.back();
        card->hide();
        card->setParent(0);
        mDeck->pushCard(card);

        mCards.pop_back();
    }
}

int Board::countFreeCells()
{
    int count = 0;
    std::vector<Freecell*>::iterator it;
    for (it = mFreeCells.begin(); it < mFreeCells.end(); it++) {
        if ((*it)->isEmpty()) {
            count++;
        }
    }

    return count;
}

bool Board::hasEnoughFreecells(int cardsToMove)
{
    int capability = countFreeCells() + 1;

    return capability >= cardsToMove;
}

void Board::freeCard(Card* card)
{
    Card* cell = 0;//getFreeCell();
    if (cell) {
        cell = card;
    }
}

void Board::automaticMove(Card* card)
{
    if (tryAutomaticAceMove(card)) {
        return;
    }

    AbstractCardHolder* bottomSpot;
    if (!card->isStackable()) {
        for (int i = 0; i < NB_COLUMNS; i++) {
            bottomSpot = mColumns[i];
            while (bottomSpot->getChild()) {
                // get the bottom card of the column
                bottomSpot = bottomSpot->getChild();
            }
            if (bottomSpot->canStackCard(card)) {
                card->setParent(bottomSpot, true);
                return;
            }
        }
    }

    std::vector<Freecell*>::iterator itFreecell;
    for (itFreecell = mFreeCells.begin(); itFreecell < mFreeCells.end(); itFreecell++) {
        if ((*itFreecell)->isEmpty()) {
            card->setParent(*itFreecell, true);
            return;
        }
    }
}

bool Board::tryAutomaticAceMove(Card* card)
{
    if (card) {
        std::vector<AceSpot*>::iterator itAce;
        AbstractCardHolder* holder = 0;
        for (itAce = mAceSpots.begin(); itAce < mAceSpots.end(); itAce++) {
            holder = *itAce;
            while (holder->getChild()) {
                holder = holder->getChild();
            }
            if (holder->canStackCard(card)) {
                unselectCard();
                selectCard(card);
                holder->select();
                return true;
            }
        }
    } else {
        for (int i = 0; i < NB_COLUMNS; i++) {
            if (mColumns[i]->getChild()) {
                card = mColumns[i]->getChild();
                while (card->getChild()) {
                    // get the bottom card of the column
                    card = card->getChild();
                }
                if (tryAutomaticAceMove(card)) {
                    // search for another card to move
                    tryAutomaticAceMove();
                }
            }
        }
    }
    return false;
}

void Board::unselectCard()
{
    if (mSelectedCard) {
        mSelectedCard->setSelected(false);
        mSelectedCard = 0;
    }
}

void Board::selectCard(Card* card)
{
    if (mSelectedCard == card) {
        unselectCard();
    } else if (mSelectedCard && card->canStackCard(mSelectedCard)) {
        if (card->isOnAceSpot()) {
            mSelectedCard->setOnAceSpot(true);
        }
        mSelectedCard->setParent(card, true);
    } else {
        if (mSelectedCard) mSelectedCard->updatePosition(true);
        setSelectedCard(card);
    }
}

void Board::setSelectedCard(Card* card)
{
    if (mSelectedCard) {
        mSelectedCard->setSelected(false);
    }
    mSelectedCard = card;
    mSelectedCard->setSelected(true);
}

Card* Board::getSelectedCard()
{
    return mSelectedCard;
}
