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

#include "cardproxy.h"
#include "card.h"
#include "cardspotproxy.h"

#include <QGraphicsSceneMouseEvent>
#include <QWidget>
#include <QGraphicsScene>

/*!
 * \brief Constructor
 * \param card The card linked to this proxy
 */
CardProxy::CardProxy(Card* card) :
    QGraphicsProxyWidget()
{
    mCard = card;
    setData(0, QVariant("card"));
}

/*!
 * \brief Handles mouse press events
 * \param event The mouse event
 */
void CardProxy::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        if (!mCard->isSelected()) {
            mCard->select();
            mCard->setZIndex(100);
        }
    } else if (event->button() == Qt::RightButton) {
        mCard->setZIndex(mCard->getTopZIndex(), false);
    }
}

/*!
 * \brief Handles mouse release events
 * \param event The mouse event
 */
void CardProxy::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::RightButton) {
        if (mCard->getChild() == 0) {
            mCard->automaticMove();
        } else {
            int index = 1;
            if (mCard->getParent()) {
                index = mCard->getParent()->getZIndex() + 1;
            }
            mCard->setZIndex(index, false);
        }
    } else if (event->button() == Qt::LeftButton) {
        QList<QGraphicsItem*> items = this->scene()->items(event->scenePos());
        bool selection = false;

        // if the card is not moved enough, replace it
        if ((event->buttonDownScenePos(Qt::LeftButton) - event->scenePos()).manhattanLength() < 10) {
            mCard->updatePosition(true);
            return;
        }

        // browse the items underneath
        for (int i = 0; i < items.size(); i++) {
            if (items[i] != this && items[i]->data(0) == QVariant("card")) {
                CardProxy* proxy = dynamic_cast<CardProxy*>(items[i]);
                if (proxy->mCard->getChild() == 0) {
                    proxy->mCard->select();
                    selection = true;
                }
                break;
            } else if (items[i] != this && items[i]->data(0) == QVariant("acespot")) {
                CardSpotProxy* proxy = dynamic_cast<CardSpotProxy*>(items[i]);
                proxy->select();
                selection = true;
                break;
            } else if (items[i] != this && items[i]->data(0) == QVariant("freecell")) {
                CardSpotProxy* proxy = dynamic_cast<CardSpotProxy*>(items[i]);
                proxy->select();
                selection = true;
                break;
            }
        }
        // if not item matches, replace the card at it's original position
        if (!selection) {
            mCard->updatePosition(true);
        }
    }
}

/*!
 * \brief Handles mouse mouse events
 * \param event The mouse event
 */
void CardProxy::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton) {
        mCard->setZIndex(100);
        mCard->setPosition(event->scenePos().toPoint() - event->buttonDownPos(Qt::LeftButton).toPoint());
    }
}
