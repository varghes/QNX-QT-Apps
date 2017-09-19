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

#include "abstractcardholder.h"

/*!
 * \brief Construtor
 */
AbstractCardHolder::AbstractCardHolder()
{
    mParent = 0;
    mChild = 0;
}

AbstractCardHolder* AbstractCardHolder::getParent()
{
    return mParent;
}

void AbstractCardHolder::setChild(Card* card)
{
    mChild = card;
}

Card* AbstractCardHolder::getChild()
{
    return mChild;
}

int AbstractCardHolder::getZIndex()
{
    return 0;
}
