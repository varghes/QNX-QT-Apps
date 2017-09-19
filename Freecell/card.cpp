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

#include "card.h"
#include "cardwidget.h"
#include "cardproxy.h"
#include "board.h"

#include <QPropertyAnimation>

#include <iostream>
#include <sstream>

/*!
 * \brief Constructor
 * \param color The color of the card
 * \param value The value of the card
 * \param board The board of the game
 */
Card::Card(int color, int value, Board* board) : AbstractCardHolder()
{
    mChild = 0;
    mColor = (cardcolor)color;
    mValue = (cardvalue)value;
    mBoard = board;
    mIsOnAceSpot = false;
    mSelected = false;

    mWidget = new CardWidget();
    mWidget->setText(getLabel());
    mWidget->setColor(getColor());
    setSelected(false);

    mProxy = new CardProxy(this);
    mProxy->setWidget(mWidget);
    mBoard->addItem(mProxy);
}

/*!
 * \brief Get a string for displaying the card's identity
 * \return QString
 */
QString Card::getLabel()
{
    return getValueName() + " of " + getColorName();
}

/*!
 * \brief Change the parent of the card and update the position accordingly
 * \param parent  The new parent
 * \param animate If set to true, the position will change through an animation
 */
void Card::setParent(AbstractCardHolder* parent, bool animate)
{
    if (mParent) {
        mParent->setChild(0);
    }
    mParent = parent;
    if (mParent) {
        mParent->setChild(this);
        updatePosition(animate);
        mBoard->unselectCard();
    }
}

/*!
 * \brief Get the number of cards stacked over this one
 * \return int
 */
int Card::countChildren()
{
    if (mChild == 0) {
        return 0;
    }
    return mChild->countChildren() + 1;
}

/*!
 * \brief Check if a card can be stacked over this one
 * \param card The card to check
 * \return boolean
 */
bool Card::canStackCard(Card* card)
{
    return isStackable() && getChild() == 0 && card->isMovable() && isValidParentOf(card);
}

/*!
 * \brief Check if the card can receive other cards over itself
 * \return boolean
 */
bool Card::isStackable()
{
    return mParent->isStackable();
}

/*!
 * \brief Check if the card can be moved from its current spot
 * \return boolean
 */
bool Card::isMovable()
{
    if (mIsOnAceSpot) {
        return false;
    }
    if (mChild == 0) {
        return true;
    }
    return isValidParentOf(mChild) && mChild->isMovable() && mBoard->hasEnoughFreecells(countChildren() + 1);
}

/*!
 * \brief Check if a given card's color and value allows it to be stacked over this one
 * \param card The card to check
 * \return
 */
bool Card::isValidParentOf(Card* card)
{
    if (card == 0) {
        return true;
    }
    if (mIsOnAceSpot) {
        return getValue() - card->getValue() == -1 && card->getColor() == getColor();
    }
    return getValue() - card->getValue() == 1 && card->getBlackRedColor() != getBlackRedColor();
}

/*!
 * \brief The the "ace spot" flag of the card
 * The flag is used for the stacking behaviour, as ace spot only receive card of the same colour
 * in ascendant order
 * \param on The new value
 */
void Card::setOnAceSpot(bool on)
{
    mIsOnAceSpot = on;
}

/*!
 * \brief Getter for the "ace spot" flag
 * \return boolean
 */
bool Card::isOnAceSpot()
{
    return mIsOnAceSpot;
}

/*!
 * \brief Get the value of this card as a string
 * \return QString
 */
QString Card::getValueName()
{
    QString cardValue = "";

    switch (mValue) {
    case ACE:
        cardValue = "ACE";
        break;
    case JACK:
        cardValue = "JACK";
        break;
    case QUEEN:
        cardValue = "QUEEN";
        break;
    case KING:
        cardValue = "KING";
        break;
    default:
        std::stringstream ss;
        ss << mValue;
        cardValue = ss.str().c_str();
        break;
    }

    return cardValue;
}

/*!
 * \brief Get the color of this card as a string
 * \return QString
 */
QString Card::getColorName()
{
    QString colorName = "";

    switch (mColor) {
    case HEARTS:
        colorName = "HEARTS";
        break;
    case DIAMONDS:
        colorName = "DIAMONDS";
        break;
    case SPADES:
        colorName = "SPADES";
        break;
    case CLUBS:
        colorName = "CLUBS";
        break;
    }

    return colorName;
}

cardvalue Card::getValue()
{
    return mValue;
}

cardcolor Card::getColor()
{
    return mColor;
}

/*!
 * \brief Convert the color of the card to the "real" (red or black) color
 * \return 1 or 2
 */
char Card::getBlackRedColor()
{
    if (mColor == HEARTS || mColor == DIAMONDS) {
        return 1;
    }
    return 2;
}

QPoint Card::getChildPosition()
{
    QPoint pos = getPosition();
    int x = pos.x();
    int y = pos.y();
    if (!mIsOnAceSpot) {
        y += + CardWidget::HEIGHT / 8;
    }

    return QPoint(x, y);
}

/*!
 * \brief Get the position of the card in board coordinates
 * \return QPoint
 */
QPoint Card::getPosition()
{
    return mPosition;
}

void Card::animatePosition(QPoint pos)
{
    mPosition = pos;
    setZIndex(100);

    QPropertyAnimation *animation = new QPropertyAnimation(mWidget, "pos");
    animation->setDuration(100);
    animation->setStartValue(mWidget->pos());
    animation->setEndValue(mPosition);
    animation->start(QAbstractAnimation::DeleteWhenStopped);

    QObject::connect(animation, SIGNAL(finished()), this, SLOT(resetZIndex()));

    if (mChild) {
        mChild->updatePosition(true);
    }
}

/*!
 * \brief Change the position of the card and its children to pos
 * \param pos The new position
 */
void Card::setPosition(QPoint pos)
{
    mPosition = pos;
    mWidget->move(mPosition);
    if (mChild) {
        mChild->updatePosition();
    }
}

/*!
 * \brief Replace the card to its expected position
 * \param animate Flag for animating the position update
 */
void Card::updatePosition(bool animate)
{
    if (animate) {
        animatePosition(mParent->getChildPosition());
    } else {
        setPosition(mParent->getChildPosition());
        setZIndex(mParent->getZIndex() + 1);
    }
}

/*!
 * \brief Get the minimum zindex for the card to be visible over all its children
 * \return int
 */
int Card::getTopZIndex()
{
    if (mChild) {
        return mChild->getTopZIndex();
    }
    return getZIndex() + 1;
}

/*!
 * \brief Getter for the zindex of the card
 * \return int
 */
int Card::getZIndex()
{
    return mProxy->zValue();
}

/*!
 * \brief Set the zindex of the card
 * \param index   The new value
 * \param cascade If set to true, the children are also updated
 */
void Card::setZIndex(int index, bool cascade)
{
    mProxy->setZValue(index);
    if (mChild && cascade) {
        mChild->setZIndex(index + 1);
    }
}

void Card::resetZIndex()
{
    setZIndex(mParent->getZIndex() + 1);
}

/*!
 * \brief Display the card
 */
void Card::show()
{
    mWidget->show();
}

/*!
 * \brief Hide the card
 */
void Card::hide()
{
    mWidget->hide();
}

void Card::select()
{
    mBoard->selectCard(this);
}

/*!
 * \brief Update the card design so it is selected or not
 * \param selected The new sselected status
 */
void Card::setSelected(bool selected)
{
    mSelected = selected;
    if (mSelected) {
        mWidget->setStyleSheet("CardWidget {background-color:white;border: 2px solid yellow;border-radius:5px;}");
    } else {
        mWidget->setStyleSheet("CardWidget {background-color:white;border: 2px solid black;border-radius:5px;}");
    }
}

/*!
 * \brief Check if the card is selected
 * \return boolean
 */
bool Card::isSelected()
{
    return mSelected;
}

/*!
 * \brief Attempt automatic move with this card
 * \see Board::automaticMove()
 */
void Card::automaticMove()
{
    mBoard->automaticMove(this);
}
