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

#include "cardspot.h"
#include <QGraphicsProxyWidget>
#include <QPointF>
#include "card.h"
#include "board.h"

/*!
 * \brief Constructor
 * \param board The board
 */
CardSpot::CardSpot(Board* board) : AbstractCardHolder()
{
    mProxy = 0;
    mBoard = board;
}

/*!
 * \brief Check if the card stop is free, i.e. has no card stacked
 * \return boolean
 */
bool CardSpot::isEmpty()
{
    return mChild == 0;
}

/*!
 * \brief Check if a card can be stacked on this spot
 * \param card The card to check
 * \return boolean
 */
bool CardSpot::canStackCard(Card* card)
{
    return isEmpty() && card->isMovable();
}

/*!
 * \brief Check if the cards can be stacked one after another on this spot
 * \return boolean
 */
bool CardSpot::isStackable()
{
    return false;
}

/*!
 * \brief Set the position of the spot to pos
 * \param pos The position to set
 */
void CardSpot::setPosition(QPointF pos)
{
    mProxy->setPos(pos);
}

/*!
 * \brief Get the position for a child card
 * \return The desired position
 */
QPoint CardSpot::getChildPosition()
{
    return mProxy->pos().toPoint();
}

/*!
 * \brief Handle the selection of this card spot
 */
void CardSpot::select()
{
    Card* card = mBoard->getSelectedCard();
    if (card && canStackCard(card)) {
        card->setParent(this, true);
    } else if (card) {
        card->updatePosition(true);
        mBoard->unselectCard();
    }
}
