/**
 * Copyright (c) 2011 Nokia Corporation.
 */

#ifndef BUTTON_H
#define BUTTON_H

#include <QWidget>


class Button : public QWidget
{
    Q_OBJECT
    
public: // Constructor and destructor.
    Button(QSize size, QPixmap pixmap, QWidget *parent = 0);
    ~Button();
    
public: // From QWidget
    void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void paintEvent(QPaintEvent *);

private: // Data
    QSize m_size;
    QPixmap m_pixmap;
};

#endif // BUTTON_H
