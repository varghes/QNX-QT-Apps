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

#ifndef CARDWIDGET_H
#define CARDWIDGET_H

#include <QFrame>
#include <QLabel>
#include "card.h"

class CardWidget : public QFrame
{
    Q_OBJECT
public:
    CardWidget(QWidget *parent = 0);

    void setText(QString);
    void setColor(cardcolor color);

    const static int WIDTH = 140;
    const static int HEIGHT = 230;

protected:

    QLabel* mLabel;
    QLabel* mColorLabel;
    QLabel* mBigColorLabel;
};

#endif // CARDWIDGET_H
