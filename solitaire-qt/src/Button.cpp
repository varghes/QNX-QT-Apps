/**
 * Copyright (c) 2011-2014 Microsoft Mobile.
 */

#include "Button.h"

#include <QApplication>
#include <QPainter>
#include <QPaintEvent>


Button::Button(QSize size, QPixmap pixmap, QWidget *parent)
    : QWidget(parent)
{
    m_size = size;
    m_pixmap = pixmap;
    m_pixmap = m_pixmap.scaled(m_size,Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
}

Button::~Button()
{
}

void Button::mousePressEvent(QMouseEvent *e)
{
    e->accept();
}

void Button::mouseReleaseEvent(QMouseEvent *e)
{
    e->accept();
    QApplication::instance()->exit();
}

void Button::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(0,0,m_pixmap);
}
