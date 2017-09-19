/**
 * Copyright (c) 2011-2014 Microsoft Mobile.
 */

#include <QAction>
#include <QApplication>
#include <QDebug>
#include <QDesktopWidget>
#include <QMenuBar>
#include <QPainter>
#include <QResizeEvent>

#include "Button.h"
#include "GameLogic.h"
#include "SolitaireScene.h"
#include "SolitaireView.h"
#include "TableauWidget.h"


TableauWidget::TableauWidget(QWidget *parent)
    : QMainWindow(parent),
      m_graphicsView(0),
      m_graphicsScene(0),
      m_exitButton(0)
{
    setWindowTitle("Solitaire");
    createMenus();
    
    // Create gamelogic and mess cards
    GameLogic *gameLogic = new GameLogic(this);
    gameLogic->messCards();

    // Create Qt Graphics View Framework classes
    m_graphicsScene = new SolitaireScene(gameLogic);
    m_graphicsScene->setItemIndexMethod(QGraphicsScene::NoIndex);

    m_graphicsView = new SolitaireView(m_graphicsScene, this);
    m_graphicsView->setDragMode(QGraphicsView::NoDrag);
    m_graphicsView->setCacheMode(QGraphicsView::CacheBackground);
    m_graphicsView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    setCentralWidget(m_graphicsView);

    // Set background color
    m_graphicsView->setBackgroundBrush(QBrush(QColor(0,128,0)));

    QPalette pal = this->palette();
    pal.setColor(QPalette::Background, QColor(0,128,0));
    this->setPalette(pal);

    // Disable scrollbars
    m_graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    
    // Deal cards into decks
    m_graphicsScene->createDecks();

    // Exit button
#ifdef Q_OS_SYMBIAN
    QPixmap p;
    p.load(":/images/exit.png");
    m_exitButton = new Button(QSize(40,40), p, this);
#endif
}

TableauWidget::~TableauWidget()
{
}

void TableauWidget::createMenus()
{
    // Add item into menu
#if defined(Q_OS_SYMBIAN)
    // into Symbian Options menu
    QAction *exitAction = new QAction(tr("&Exit"), this);
    menuBar()->addAction(exitAction);
    connect(exitAction, SIGNAL(triggered()), this, SLOT(close()));
#elif defined(Q_WS_MAEMO_5)
    // into Maemo
    QAction *closeAction = new QAction(tr("C&lose"), this);
    menuBar()->addAction(closeAction);
    connect(closeAction, SIGNAL(triggered()), this, SLOT(close()));
#elif defined(Q_WS_MAEMO_6)
    // No menus for Harmattan.
#else
    // else
    QMenu *optionsMenu = menuBar()->addMenu(tr("&File"));
    QAction *exitAction = new QAction(tr("&Exit"), this);
    optionsMenu->addAction(exitAction);
    connect(exitAction, SIGNAL(triggered()), this, SLOT(close()));
#endif
}

QSize TableauWidget::sizeHint() const
{
    // This property holds the recommended size for the widget
    return m_widgetSize;
}


void TableauWidget::resizeEvent (QResizeEvent* event)
{
    // This event handler can be reimplemented in a subclass to receive widget
    // resize events which are passed in the event parameter. 
    // When resizeEvent() is called, the widget already has its new geometry.
    
    m_widgetSize = event->size();
    
    // Update graphics scene and view sizes
    m_graphicsScene->setSceneRect(m_graphicsView->rect());
    m_graphicsScene->updatePositions(m_graphicsView->rect());

    // Exit button position to top right
#ifdef Q_OS_SYMBIAN
    m_exitButton->setGeometry(width() - 45, 5, 40, 40);
#endif

    QWidget::resizeEvent(event);
}
