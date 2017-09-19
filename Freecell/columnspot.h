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

#ifndef COLUMNSPOT_H
#define COLUMNSPOT_H

#include "cardspot.h"

class Board;

class ColumnSpot : public CardSpot
{
public:
    ColumnSpot(Board*);
    bool isStackable();
    bool canStackCard(Card *);
};

#endif // COLUMNSPOT_H
