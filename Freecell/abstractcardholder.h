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

#ifndef ABSTRACTCARDHOLDER_H
#define ABSTRACTCARDHOLDER_H

#include <QObject>

class QPoint;
class Card;

class AbstractCardHolder : public QObject
{
public:
    AbstractCardHolder();
    AbstractCardHolder* getParent();

    virtual void setChild(Card*);
    Card* getChild();

    virtual bool canStackCard(Card* card) = 0;
    virtual bool isStackable() = 0;
    virtual void select() = 0;

    virtual QPoint getChildPosition() = 0;
    virtual int getZIndex();

protected:
    AbstractCardHolder* mParent;
    Card* mChild;
};

#endif // ABSTRACTCARDHOLDER_H
