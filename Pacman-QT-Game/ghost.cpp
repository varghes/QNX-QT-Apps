#include "ghost.h"

Ghost::Ghost()
{
    animestate=0;

    gosx=450/2;
    gosy=480/2;

    direction=1;
    is_Scared=false;
    whiteb=false;

    //Loads ghosts images.
    right1.load(":/images/ghostright1.png");
    right2.load(":/images/ghostright2.png");
    up1.load(":/images/ghostup1.png");
    up2.load(":/images/ghostup2.png");
    down1.load(":/images/ghostdown1.png");
    down2.load(":/images/ghostdown2.png");
    left1.load(":/images/ghostleft1.png");
    left2.load(":/images/ghostleft2.png");
    scareb.load(":/images/ghostscaredblue1.png");
    scareb1.load(":/images/ghostscaredblue2.png");
    scarew.load(":/images/ghostscaredwhite1.png");
    scarew1.load(":/images/ghostscaredwhite2.png");

}

QRectF Ghost::boundingRect() const
{
    return QRect(gosx-15,gosy-15,20,20);
}

void Ghost::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setOpacity(0.5); // makes the ghosts actually look like ghosts
    if(!is_Scared){
        switch(direction){
            case 1:
                if(animestate==0){
                    painter->drawPixmap(gosx-15,gosy-15,30,30,left1);
                }else{
                    painter->drawPixmap(gosx-15,gosy-15,30,30,left2);
                }
                break;
            case 4:
                if(animestate==0){
                    painter->drawPixmap(gosx-15,gosy-15,30,30,right1);
                }else{
                    painter->drawPixmap(gosx-15,gosy-15,30,30,right2);
                }
                break;
            case 3:
                if(animestate==0){
                    painter->drawPixmap(gosx-15,gosy-15,30,30,down1);
                }else{
                    painter->drawPixmap(gosx-15,gosy-15,30,30,down2);
                }
                break;
            case 2:
                if(animestate==0){
                    painter->drawPixmap(gosx-15,gosy-15,30,30,up1);
                }else{
                    painter->drawPixmap(gosx-15,gosy-15,30,30,up2);
                }
                break;
        }
    }else{
        if(whiteb){
            if(animestate==0){
                painter->drawPixmap(gosx-15,gosy-15,30,30,scareb);
            }else{
                painter->drawPixmap(gosx-15,gosy-15,30,30,scarew1);
            }
        }else{
            if(animestate==0){
                painter->drawPixmap(gosx-15,gosy-15,30,30,scareb);
            }else{
                painter->drawPixmap(gosx-15,gosy-15,30,30,scareb1);
            }
        }

    }

}

void Ghost::advance()
{
    if(animestate>2){
        animestate=0;
    }else{
        animestate++;
    }
}

void Ghost::setgosx(int x)
{
    gosx=x;
}

void Ghost::setgosy(int y)
{
    gosy=y;
}

void Ghost::setDirection(int dir)
{
    direction=dir;
}

void Ghost::setColor(QString col)
{ // Because each ghost is different colours they need to be called differently
    if(col=="blue"){
        right1.load(":/images/ghostrightblue1.png");
        right2.load(":/images/ghostrightblue2.png");
        up1.load(":/images/ghostupblue1.png");
        up2.load(":/images/ghostupblue2.png");
        down1.load(":/images/ghostdownblue1.png");
        down2.load(":/images/ghostdownblue2.png");
        left1.load(":/images/ghostleftblue1.png");
        left2.load(":/images/ghostleftblue2.png");
    }else if(col=="orange"){
        right1.load(":/images/ghostrightorange1.png");
        right2.load(":/images/ghostrightorange2.png");
        up1.load(":/images/ghostuporange1.png");
        up2.load(":/images/ghostuporange2.png");
        down1.load(":/images/ghostdownorange1.png");
        down2.load(":/images/ghostdownorange2.png");
        left1.load(":/images/ghostleftorange1.png");
        left2.load(":/images/ghostleftorange2.png");
    }else if(col=="red"){
        right1.load(":/images/ghostrightred1.png");
        right2.load(":/images/ghostrightred2.png");
        up1.load(":/images/ghostupred1.png");
        up2.load(":/images/ghostupred2.png");
        down1.load(":/images/ghostdownred1.png");
        down2.load(":/images/ghostdownred2.png");
        left1.load(":/images/ghostleftred1.png");
        left2.load(":/images/ghostleftred2.png");
    }
}
