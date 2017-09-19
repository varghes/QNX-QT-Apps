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

#ifndef DECK_H
#define DECK_H

#include <vector>

class Board;
class Card;

/*!
 * \brief A card deck
 */
class Deck
{
public:
    Deck(Board* board);

    void shuffle();
    Card* drawCard();
    void pushCard(Card*);

    int getSize();

protected:
    void build(Board* board);

    std::vector<Card*> mCards;

};

#endif // DECK_H
