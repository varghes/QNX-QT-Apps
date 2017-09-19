/**
 * Copyright (c) 2011 Nokia Corporation.
 */

#ifndef TABLEAUWIDGET_H
#define TABLEAUWIDGET_H

#include <QMainWindow>

// Forward declarations
class SolitaireView;
class SolitaireScene;
class Button;


class TableauWidget : public QMainWindow
{
    Q_OBJECT
    
public: // Constructor and destructor
    TableauWidget(QWidget *parent = 0);
    ~TableauWidget();
    
private:
    void resizeEvent(QResizeEvent* event);
    QSize sizeHint() const;
    void createMenus();
        
private: // Data
    SolitaireView *m_graphicsView; // Owned
    SolitaireScene *m_graphicsScene; // Owned
    Button *m_exitButton; // Owned
    QSize m_widgetSize;
};

#endif // TABLEAUWIDGET_H
