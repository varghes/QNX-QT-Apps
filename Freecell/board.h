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

#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <QObject>

#include "card.h"
#include "deck.h"

class QGraphicsProxyWidget;
class QGraphicsView;
class QWidget;

class AceSpot;
class ColumnSpot;
class Freecell;
class BoardScene;

class Board : public QObject
{
    Q_OBJECT
public:
    Board();

    void dealCards();
    void collectCards();

    void freeCard(Card* card);
    int countFreeCells();
    bool hasEnoughFreecells(int cardsToMove);

    void automaticMove(Card*);
    void unselectCard();
    void selectCard(Card*);

    void setSelectedCard(Card*);
    Card* getSelectedCard();
    void addItem(QGraphicsProxyWidget*);

    QWidget* getBoardWidget();

public slots:
    bool tryAutomaticAceMove(Card* card = 0);

protected:
    std::vector<AceSpot*> mAceSpots;
    std::vector<Freecell*> mFreeCells;

    const static int NB_COLUMNS = 8;
    Card* mLeafColumns[NB_COLUMNS];
    ColumnSpot* mColumns[NB_COLUMNS];

    Deck* mDeck;
    QGraphicsView *mBoardWidget;
    BoardScene* mScene;

    Card* mSelectedCard;
    std::vector<Card*> mCards;
};

#endif // BOARD_H
