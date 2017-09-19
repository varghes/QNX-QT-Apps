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

#ifndef CARDSPOT_H
#define CARDSPOT_H

#include "abstractcardholder.h"

class Board;
class Card;
class QPointF;
class QGraphicsProxyWidget;

/*!
 * \brief The CardSpot class
 *
 * A card spot represents any spot on the board where a card can be stacked
 * on (freecell, empty ace spot, empty column spot).
 */
class CardSpot : public AbstractCardHolder
{
public:
    CardSpot(Board*);
    bool isEmpty();
    virtual bool canStackCard(Card* card);
    bool isStackable();
    void setPosition(QPointF pos);
    QPoint getChildPosition();

    void select();

protected:
    Board* mBoard;
    QGraphicsProxyWidget* mProxy;
};

#endif // CARDSPOT_H
