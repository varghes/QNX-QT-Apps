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

#include "cardspotproxy.h"
#include "cardspot.h"

#include <QGraphicsSceneMouseEvent>

/*!
 * \brief Constructor
 * \param cardSpot The card spot object to link
 * \param parent The parent item
 */
CardSpotProxy::CardSpotProxy(CardSpot* cardSpot, QGraphicsItem *parent) :
    QGraphicsProxyWidget(parent)
{
    mCardSpot = cardSpot;
}

/*!
 * \brief Access to the card spot object's select() method
 */
void CardSpotProxy::select()
{
    mCardSpot->select();
}

/*!
 * \brief Handles mouse press events
 * \param event The mouse event
 */
void CardSpotProxy::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        mCardSpot->select();
    }
}
