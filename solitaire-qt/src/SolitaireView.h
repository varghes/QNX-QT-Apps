/**
 * Copyright (c) 2011 Nokia Corporation.
 */

#ifndef SOLITAIREVIEW_H
#define SOLITAIREVIEW_H

#include <QGraphicsView>


class SolitaireView : public QGraphicsView
{
    Q_OBJECT
    
public:
    SolitaireView(QGraphicsScene *scene, QWidget *parent = 0);
    ~SolitaireView();
    
};

#endif // SOLITAIREVIEW_H
