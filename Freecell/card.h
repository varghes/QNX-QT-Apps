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

#ifndef CARD_H
#define CARD_H

#include <QPoint>

#include "abstractcardholder.h"

enum cardvalue {ACE=1, JACK=11, QUEEN=12, KING=13};
enum cardcolor {HEARTS=1, DIAMONDS=2, SPADES=3, CLUBS=4};

class CardWidget;
class CardProxy;
class Board;
class QPixmap;

/*!
 * \brief A Card
 */
class Card : public AbstractCardHolder
{
    Q_OBJECT
public:
    Card(int color, int value, Board* board);

    void setParent(AbstractCardHolder*, bool = false);
    int countChildren();

    bool canStackCard(Card*);
    bool isStackable();
    bool isMovable();
    bool isValidParentOf(Card*);
    void setOnAceSpot(bool);
    bool isOnAceSpot();

    QString getValueName();
    QString getColorName();
    QString getLabel();

    cardvalue getValue();
    cardcolor getColor();
    char getBlackRedColor();

    QPoint getPosition();
    QPoint getChildPosition();
    void animatePosition(QPoint pos);
    void setPosition(QPoint pos);
    void updatePosition(bool animate = false);
    int getTopZIndex();
    int getZIndex();
    void setZIndex(int index, bool cascade = true);
    void hide();
    void show();

    void select();
    bool isSelected();
    void setSelected(bool selected);
    void automaticMove();

public slots:
    void resetZIndex();

protected:
    cardcolor mColor;
    cardvalue mValue;

    Board* mBoard;
    CardWidget* mWidget;
    CardProxy* mProxy;

    QPoint mPosition;
    bool mSelected;

    bool mIsOnAceSpot;

};
#endif // CARD_H
