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

#include "acespot.h"
#include "board.h"
#include "cardwidget.h"
#include "cardspotproxy.h"
#include <QLabel>

/*!
 * \brief Constructor
 * \param board The board
 */
AceSpot::AceSpot(Board* board) : CardSpot(board)
{
    mProxy = new CardSpotProxy(this);
    mProxy->setData(0, QVariant("acespot"));
    QLabel* widget = new QLabel();
    widget->resize(CardWidget::WIDTH, CardWidget::HEIGHT);
    widget->setStyleSheet("background-color:#00FF00;border:1px solid black;color:#00AA00;");
    widget->setText("A");
    widget->setAlignment(Qt::AlignCenter);

    QFont font = widget->font();
    font.setPixelSize(CardWidget::HEIGHT * 0.4);
    widget->setFont(font);

    mProxy->setWidget(widget);
    mBoard->addItem(mProxy);
}

/*!
 * \brief Check if a card can be stacked on this spot
 * \param card The card to check
 * \return boolean
 */
bool AceSpot::canStackCard(Card* card)
{
    if (CardSpot::canStackCard(card) && card->getValue() == ACE) {
        return true;
    }
    return false;
}

/*!
 * \brief Check if the cards can be stacked one after another on this spot
 * \return boolean
 */
bool AceSpot::isStackable()
{
    return true;
}

/*!
 * \brief Set a new card as child of this spot
 * \param card The card
 */
void AceSpot::setChild(Card* card)
{
    CardSpot::setChild(card);
    if (card) {
        card->setOnAceSpot(true);
    }
}
