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

#include "mainwindow.h"
#include "board.h"
#include <QMenuBar>
#include <QApplication>

/*!
 * \brief Constructor
 * \param parent The parent widget
 */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{

    QMenu* fileMenu = new QMenu("File");
    fileMenu->addAction("New game", this, SLOT(newGame()));
    fileMenu->addAction("Quit", qApp, SLOT(quit()));
    menuBar()->addMenu(fileMenu);

    setWindowTitle("Freecell");

    mBoard = new Board();
    QWidget* widget = mBoard->getBoardWidget();
    setCentralWidget(widget);

    newGame();
}

/*!
 * \brief Start a new game
 */
void MainWindow::newGame()
{
    endGame();
    mBoard->dealCards();
}

/*!
 * \brief Triggers the end of a game
 */
void MainWindow::endGame()
{
    mBoard->collectCards();
}
