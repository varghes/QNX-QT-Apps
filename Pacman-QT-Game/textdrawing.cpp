#include "textdrawing.h"

TextDrawing::TextDrawing()
{
    over=false;
    w=350;
    h=50;
    x=450/2-w/2;
    y=480/2-h/2;
    score=0;
    playing=false;
    paused=false;

}
// setting locations on the screen for the writting
QRectF TextDrawing::boundingRect() const
{
    return QRect(x, y, w, h);
}
// a bool to check if the game over
void TextDrawing::SetOver(bool over)
{
    this->over=over;
}

// this method draws all the text at the beginning, during, end of the game.
void TextDrawing::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPen pen(Qt::blue);
    painter->setPen(pen);
    QFont font=painter->font() ;


    if(!playing){
        font.setPointSize ( 18 );
         painter->setFont(font);


        if(over){
            font.setPointSize ( 32 );
            QPen pen(Qt::red);
            painter->setPen(pen);
             painter->setFont(font);
             painter->drawText( x+80,y-180, "GAME OVER" );
             font.setPointSize ( 18 );
             QPen highPen(Qt::yellow);
             painter->setPen(highPen);
              painter->setFont(font);
             painter->drawText( x+120,y-110, "HIGHSCORE" );
             painter->drawText( x+0,y-70, "Tom" );
             painter->drawText( x+80,y-70, QString::number(score+1000));
             painter->drawText( x+140,y-70, "Ultra Hard" );
              painter->drawText( x+250,y-70, "1000 Seconds" );
             painter->drawText( x+0,y-50, name );
             painter->drawText( x+80,y-50, QString::number(score));
             painter->drawText( x+140,y-50, difficulty );
              painter->drawText( x+250,y-50, QString::number(timeElapsed)+" Seconds" );
             painter->drawText( x+0,y-30, "Jeff" );
             painter->drawText( x+80,y-30, QString::number(score-10));
             painter->drawText( x+140,y-30, difficulty );
             painter->drawText( x+250,y-30, "53 Seconds" );
             painter->drawText( x+0,y-10, "AAA" );
             painter->drawText( x+80,y-10, QString::number(score-100));
             painter->drawText( x+140,y-10, "medium" );
             painter->drawText( x+250,y-10, "89 Seconds" );
             painter->drawText( x+0,y+10, "Doug" );
             painter->drawText( x+80,y+10, QString::number(score-200));
             painter->drawText( x+140,y+10, "easy" );
             painter->drawText( x+250,y+10, "100 Seconds" );
//              painter->drawText( x+80,y-300, "Press Space to play again" );

        }else{

              painter->drawText( boundingRect(),Qt::AlignCenter, "PRESS SPACE TO START" );
            font.setPointSize ( 32 );
            QPen pen(Qt::yellow);
            painter->setPen(pen);
             painter->setFont(font);
             painter->drawText( x+100,y-180, "Pac Man" );





        }


    }

    if(paused  && !over)
   {
          font.setPointSize ( 18 );
           painter->setFont(font);
           QPen pen(Qt::red);
           painter->setPen(pen);
                   painter->drawText(boundingRect(), Qt::AlignCenter, "PAUSE");
      }


}

