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

#include "deck.h"
#include "card.h"
#include <stdlib.h>

/*!
 * \brief Constructor
 * \param board The board
 */
Deck::Deck(Board* board)
{
    build(board);
}

/*!
 * \brief Shuffle the cards in this deck
 *
 * The cards are randomly reordered in the deck. Any number of cards can be
 * present in the deck.
 */
void Deck::shuffle()
{
    char c;
    std::vector<Card*> tmpCards;
    std::vector<Card*>::iterator it;

    while (mCards.size()) {
        c = rand() % mCards.size();
        it = mCards.begin() + c;
        tmpCards.push_back(*it);
        mCards.erase(it);
    }
    mCards = tmpCards;
}

/*!
 * \brief Build the deck
 *
 * The function creates the cards ordered by color and vale
 * and adds them to the deck successively.
 *
 * \param board The board
 */
void Deck::build(Board* board)
{
	int i;
	int  j;
    mCards.clear();

   // for (cardcolor i = HEARTS; i<= CLUBS; i++) {
    //    for (cardvalue j = ACE; j <= KING; j++) {
		
    for ( i = HEARTS; i<= CLUBS; i++) {
        for ( j = ACE; j <= KING; j++) {
            pushCard(new Card(i, j, board));
        }
    }
}

/*!
 * \brief Draw the last card from the deck
 * \return A card
 */
Card* Deck::drawCard()
{
    Card* card = mCards.back();
    mCards.pop_back();

    return card;
}

/*!
 * \brief Push a card at the end of the deck
 * \param card The card to add
 */
void Deck::pushCard(Card* card)
{
    mCards.push_back(card);
}

/*!
 * \brief Get the number of cards in the deck
 * \return The size (int)
 */
int Deck::getSize()
{
    return mCards.size();
}
