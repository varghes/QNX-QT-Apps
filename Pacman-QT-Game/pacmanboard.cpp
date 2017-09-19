#include "pacmanboard.h"


PacmanBoard::PacmanBoard()
{

mappic.load(":/images/pac_map_old.png");
ball=new Ball;
powerball=new PowerBall;

AddPathPoints(30, 30, 200, 30);
AddPathPoints(250, 30, 420, 30);
AddPathPoints(30, 90, 420, 90);
AddPathPoints(30, 130, 110, 130);
AddPathPoints(150, 130, 200, 130);
AddPathPoints(250, 130, 300, 130);
AddPathPoints(340, 130, 420, 130);
AddPathPoints(150, 180, 300, 180);
AddPathPoints(0, 230, 150, 230);
AddPathPoints(300, 230, 450, 230);
AddPathPoints(150, 270, 300, 270);
AddPathPoints(30, 320, 200, 320);
AddPathPoints(250, 320, 420, 320);
AddPathPoints(30, 360, 60, 360);
AddPathPoints(110, 360, 340, 360);
AddPathPoints(390, 360, 420, 360);
AddPathPoints(30, 410, 110, 410);
AddPathPoints(150, 410, 200, 410);
AddPathPoints(250, 410, 300, 410);
AddPathPoints(340, 410, 420, 410);
AddPathPoints(30, 450, 420, 450);

AddPathPoints(30, 30, 30, 130);
AddPathPoints( 30, 320, 30, 360);
AddPathPoints(30, 410, 30, 450);
AddPathPoints( 60, 360, 60, 410);
AddPathPoints(110, 30, 110, 410);
AddPathPoints( 150, 90, 150, 130);
AddPathPoints(150, 180, 150, 320);
AddPathPoints(150, 360, 150, 410);
AddPathPoints( 200, 30, 200, 90);
AddPathPoints(200, 135, 200, 180);
AddPathPoints( 200, 320, 200, 360);
AddPathPoints( 200, 410, 200, 450);
AddPathPoints( 250, 30, 250, 90);
AddPathPoints( 250, 135, 250, 180);
AddPathPoints( 250, 320, 250, 360);
AddPathPoints( 250, 410, 250, 450);
AddPathPoints( 300, 90, 300, 130);
AddPathPoints( 300, 180, 300, 320);
AddPathPoints( 300, 360, 300, 410);
AddPathPoints( 340, 30, 340, 410);
AddPathPoints( 390, 360, 390, 410);
AddPathPoints( 420, 30, 420, 130);
AddPathPoints( 420, 320, 420, 360);
AddPathPoints( 420, 410, 420, 450);
QPoint p;
QPoint p1,p2,p3,p4;
p1.setX(30);
p1.setY(450);
p2.setX(30);
p2.setY(35);
p3.setX(420);
p3.setY(35);
p4.setX(420);
p4.setY(450);
powerballpoints.push_front(p1);
powerballpoints.push_front(p2);
powerballpoints.push_front(p3);
powerballpoints.push_front(p4);


// This is an algorithm found on pacman tutorials to set the balls corresponding a pacman map
for (int i=0; i<450-1; i++)
{
    for(int j=0;j<480-1;j++){
        p.setX(i);
        p.setY(j);

        if(j%10==0 && i%10==0){
            if (pacpoints.contains(p)){
                if(p!=p1 && p!=p2 && p!=p3 && p!=p4){
                    if(p.x()>0){
                        ballpoints.push_front(p);
                    }
                }

             }
        }

    }



}
generateBalls();
}

QRectF PacmanBoard::boundingRect() const
{
return QRect(0,0,450,480); //This is how big the constraints for the map are
}

void PacmanBoard::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

painter->drawPixmap(0,0,450,480,mappic);

}


void PacmanBoard::generateBalls()
{


//// Painter used to create points on the map
QPainter painter;
painter.begin(&mappic);
painter.setRenderHint(QPainter::Antialiasing);
painter.setPen(Qt::NoPen); // they don't need an outline
painter.setBrush(Qt::white); // colour


for(int i=0;i<ballpoints.size();i++){

    painter.drawEllipse(ballpoints[i].x(),ballpoints[i].y(),3,3);
}
for(int i=0;i<powerballpoints.size();i++){

    painter.setBrush(Qt::yellow);
    painter.drawEllipse(powerballpoints[i].x()-5,powerballpoints[i].y()-5,10,10);
}
}
// This creates a path behind pacman
bool PacmanBoard::canmove(QPoint point)
{

for(int i=0;i<pacpoints.size();i++){
    if(pacpoints[i]==point)
    {
         return true;
     }
}
return false;


}
// This draws the path behind pacman with colour, but colour is set to black
void PacmanBoard::fillpacpoints(int pacx, int pacy)
{

QPainter painter;
QRect rec(pacx,pacy,3,3);
QRect rec2(pacx-5,pacy-5,10,10);

painter.begin(&mappic);
painter.fillRect(rec,Qt::black); // producing a trail behind pacman
// This will paint over the powerball points once pacman has rode over them
if((pacx==powerballpoints[0].x() && pacy==powerballpoints[0].y())||
       (pacx==powerballpoints[1].x() && pacy==powerballpoints[1].y())||
       (pacx==powerballpoints[2].x() && pacy==powerballpoints[2].y())||
       (pacx==powerballpoints[3].x() && pacy==powerballpoints[3].y())){
   painter.fillRect(rec2,Qt::black);
}
painter.end();
}

void PacmanBoard::setballpoints(QVector<QPoint> points)
{
ball->setpoints(points);
}

void PacmanBoard::setpowerballpoints(QVector<QPoint> points)
{
powerball->setpoints(points);
}
// This locates where the points are behind pacman and push them to front.
void PacmanBoard::AddPathPoints(int x1, int y1, int x2, int y2)
{
QPoint p;

if (x1 == x2)
        {
            if (y1 < y2)
            {
                for (int y=y1; y<y2+1; y++)
                {
                    p.setX(x1);
                    p.setY(y);
                    if (! pacpoints.contains(p)){pacpoints.push_front(p);
                    }

                }
            }
            else
            {
                for (int y=y1; y>y2-1; y--)
                {
                    p.setX(x1);
                    p.setY(y);
                    if (! pacpoints.contains(p)){pacpoints.push_front(p);
                    }
                }
            }
        }
        else
        {
            if (x1 < x2)
            {
                for (int x=x1; x<x2+1; x++)
                {
                    p.setX(x);
                    p.setY(y1);//= new QPoint(x1, y);
                    if (! pacpoints.contains(p)){pacpoints.push_front(p);
                    }
                }
            }
            else
            {
                for (int x=x1; x>x2-1; x--)
                {
                    p.setX(x);
                    p.setY(y1);//= new QPoint(x1, y);
                    if (! pacpoints.contains(p)){pacpoints.push_front(p);
                    }

                }
            }
        }

}


QVector<QPoint> PacmanBoard::getballpoints()
{
return ballpoints;
}

QVector<QPoint> PacmanBoard::getpowerballpoints()
{
return powerballpoints;
}

