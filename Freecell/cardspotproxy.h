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

#ifndef FREECELLPROXY_H
#define FREECELLPROXY_H

#include <QGraphicsProxyWidget>

class CardSpot;

/*!
 * \brief The CardSpotProxy class
 *
 * A proxy widget that represents any card spot (freecell, ace spot, column spot).
 */
class CardSpotProxy : public QGraphicsProxyWidget
{
public:
    CardSpotProxy(CardSpot* cardSpot, QGraphicsItem *parent = 0);

    void select();

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

    CardSpot* mCardSpot;
};

#endif // FREECELLPROXY_H
