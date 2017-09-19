#ifndef TEXTDRAWING_H
#define TEXTDRAWING_H

#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>

class TextDrawing : public QGraphicsItem
{
public:
    TextDrawing();
     QRectF boundingRect() const;
     void SetOver(bool over);
      void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
      bool over,playing,paused;
      int x,y,w,h,score,timeElapsed;
      QString name, difficulty;


private:
      QTimer *timer;

};
#endif // TEXTDRAWING_H
