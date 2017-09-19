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

#ifndef CARDPROXY_H
#define CARDPROXY_H

#include <QGraphicsProxyWidget>

class Card;

/*!
 * \brief The CardProxy class
 *
 * A QGraphicsProxyWidget reimplemented in order to manage mouse events
 * over the cards of the board.
 */
class CardProxy : public QGraphicsProxyWidget
{
public:
    explicit CardProxy(Card* card);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

    Card* mCard;
};

#endif // CARDPROXY_H
