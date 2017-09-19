#include "Pacmanwindow.h"
#include "ui_Pacmanwindow.h"
#include <QThread>
//#include <qt4/QtGui/QtWidgets>
//#include <Qqt4/QtGui/QtWidget>
#include <qt4/QtGui/QWidget>
#include "options.h"


Pacmanwindow::Pacmanwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Pacmanwindow)
{


    // As windows needs this to be declared and start game, will contain different values as you can't set eveything to 0
    score=0;
    level = 0;
    lives=3; // needs to be set to a number because of lcd sometimes producing crazy numbers
    starting = 0;
    gosx=450/2;
    gosy=480/2;
    gosx1=450/2;
    gosy1=480/2;
    gosx2=450/2;
    gosy2=480/2;
    gosx3=450/2;
    gosy3=480/2;
    pacx=410/2;
    pacy=410;
    ghostmoving=false;
    ghostmoving1=false;
    ghostmoving2=false;
    ghostmoving3=false;
    scared=false;
    scared1=false;
    scared2=false;
    scared3=false;
    start=false;
    direction=0;
    moving=false;
    playing=false;
    isPaused = false;


    ///// Setting up the ui
    //Pacman(Qt::Dialog | Qt::FramelessWindowHint);
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->scoreLabel->setText(name);// adds the name tp score label

    scene->setSceneRect(0,0,640,480);
    ui->graphicsView->setSceneRect(scene->sceneRect());
    //Used to exit the application
    connect(ui->exitButton,SIGNAL(clicked()),qApp,SLOT(closeAllWindows()));
    ui->exitButton->setShortcut(QKeySequence("Escape"));


    text=new TextDrawing;
    text->over=false;
    text->paused=false;
    scene->addItem(text);
    text->setZValue(7);// This allows it to be ontop of the graphic screen





}

// A Method used to store the name and difficulty parsed from options
void Pacmanwindow::parseMessage(QString name, int temp){

    this->name = name;
    ui->scoreLabel->setText(name + "'s Score");
    difficulty = temp;
}

// A Method used to start the game both at the beginning, on new level and if there is a game over
void Pacmanwindow::start_Game()
{
    level = 0;
    direction = 0;
    //start = false;
    playing = true;
    gosx=450/2;
    gosy=480/2;
    gosx1=450/2;
    gosy1=480/2;
    gosx2=450/2;
    gosy2=480/2;
    gosx3=450/2;
    gosy3=480/2;
    pacx=400/2;
    pacy=360;
    pacman=new Pacman;
    pac_map=new PacmanBoard;
    ghost=new Ghost;
    ghost1=new Ghost;
    ghost2=new Ghost;
    ghost3=new Ghost;

    ghost1->setColor("orange");
    ghost2->setColor("red");
    ghost3->setColor("blue");

    ball=new Ball; //sets the points for pacman
    powerball=new PowerBall;// powerballs to set ghosts to blue
    ballpoints=pac_map->getballpoints();
    Powerballpoints=pac_map->getpowerballpoints();
    scene->removeItem(text); // remove the startup text ofc
    scene->addItem(pac_map);
    scene->addItem(pacman);
    scene->addItem(ghost);
    scene->addItem(ghost1);
    scene->addItem(ghost2);
    scene->addItem(ghost3);
    scene->addItem(text);

    //scene->removeItem(text);
    text->playing=true;
    ghostmoving=false;
    ghostmoving1=false;
    ghostmoving2=false;
    ghostmoving3=false;
    moving=false;
    ghoststart=false;
    ghoststart1=false;
    ghoststart2=false;
    ghoststart3=false;

    state=0;
    state1=0;
    state2=0;
    state3=0;



   // waka->play(":/Sound/pacman_beginning.wav");
    //This is used to set the difficulty level as level will always be 0 at the beginning.
    if (starting==0) // this may be a problem and if ghosts haven't
    {
        if (difficulty == 1){
            easy();
            difficultyText = "easy";
        }
        if (difficulty == 2){
            medium();
            difficultyText = "medium";
        }
        if (difficulty == 3){
            hard();
            difficultyText = "hard";
        }

    }
}
// A method used to set the difficulty
void Pacmanwindow::easy(){
// calling both timers to start the game
    timer = new QTimer(this);
    ghoststimer=new QTimer(this);
    // Connecting the timers to the signal timeout which slows down the normal speed of timer and setting each timer to there corresponding methods.
    connect(timer, SIGNAL(timeout()), this,SLOT(updater()));
    // Ghost needs a seperate timer as the ghosts will move a different speeds and need to slow down regarding if they are in scared state or not
    connect(ghoststimer, SIGNAL(timeout()), this,SLOT(ghostupdater()));
    this->show();
    scene->update();
    this->update();

    lives = 3;
    timer->start();
    timer->start(35);
    ghoststimer->start(45);
    // sets focus to everything on the screen
    this->setFocus();


}

void Pacmanwindow::medium(){
    lives =2;

    timer = new QTimer(this);
    ghoststimer=new QTimer(this);
    connect(timer, SIGNAL(timeout()), this,SLOT(updater()));
    connect(ghoststimer, SIGNAL(timeout()), this,SLOT(ghostupdater()));
    this->show();
    scene->update();
    this->update();


    timer->start();
    timer->start(50);
    ghoststimer->start(50);
    this->setFocus();


}
void Pacmanwindow::hard(){

    lives = 0; // one life
    timer = new QTimer(this);
    ghoststimer=new QTimer(this);
    connect(timer, SIGNAL(timeout()), this,SLOT(updater()));
    connect(ghoststimer, SIGNAL(timeout()), this,SLOT(ghostupdater()));
    this->show();
    scene->update();
    this->update();

    timer->start();
    timer->start(40);
    ghoststimer->start(35);
    this->setFocus();


}




// A method called when all lives are depleated resulting in changing the values.
void Pacmanwindow::end_Game()
{
    starting = 0;
    //Attempts at removing items but doesn't remove all of them
    scene->removeItem(pacman);
    scene->removeItem(ghost);
    scene->removeItem(ghost1);
    scene->removeItem(ghost2);
    scene->removeItem(ghost3);
    scene->removeItem(pac_map);
    //This displays the gameover text from the textdrawing class
    text->over=true;
    text->playing=false;
    start = false;
    playing=false;
    scene->update();
    timer->stop();
    ghoststimer->stop();
    score = hiscore;
    score = 0;

}



// This code is used when one of the livess are taken.
void Pacmanwindow::retry(){

    gosx=450/2;
    gosy=480/2;
    gosx1=450/2;
    gosy1=480/2;
    gosx2=450/2;
    gosy2=480/2;
    gosx3=450/2;
    gosy3=480/2;
    pacx=400/2;
    pacy=360;
    direction=4;
    start = true;
    ghoststart=false;
    ghoststart1=false;
    ghoststart2=false;
    ghoststart3=false;
    ghostmoving=false;
    ghostmoving1=false;
    ghostmoving2=false;
    ghostmoving3=false;
    moving=false;
    state=0;
    state1=0;
    state2=0;
    state3=0;

}

// Method for pacmans movenment and wall collisions etc..
void Pacmanwindow::pacman_move()
{
    QPoint p;
    //if the direction you choose is not the same to the current dirrection switch through these
    if(nextdirection!=direction){
        switch(nextdirection)
        {
        //  moving left...Whilst moving
        case 1:
            p.setX(pacx-5);
            p.setY(pacy);

            if(pac_map->canmove(p)){
                direction=nextdirection;
                nextdirection=0;

            }

            break;
            // moving right...whilst already moving
        case 4:
            p.setX(pacx+5);
            p.setY(pacy);
            if(pac_map->canmove(p)){
                direction=nextdirection;
                nextdirection=0;

            }
            // moving right
            break;
        case 3:
            p.setX(pacx);
            p.setY(pacy+5);
            if(pac_map->canmove(p)){
                direction=nextdirection;
                nextdirection=0;

            }
            // moving left
            break;
        case 2:
            p.setX(pacx);
            p.setY(pacy-5);
            if(pac_map->canmove(p)){
                direction=nextdirection;
                nextdirection=0;

            }

            break;
        }

    }
    switch(direction)
    {
    case 1:
        p.setX(pacx-5);
        p.setY(pacy);
        pacman->setDirection(direction);

        if(pac_map->canmove(p)){
            pacx-=5;


            moving=true;

        }else{
            moving=false;
        }

        break;

    case 4:
        pacman->setDirection(direction);
        p.setX(pacx+5);
        p.setY(pacy);
        if(pac_map->canmove(p)){
            pacx+=5;

            moving=true;

        }else{
            moving=false;
        }

        break;
    case 3:
        pacman->setDirection(direction);
        p.setX(pacx);
        p.setY(pacy+5);
        if(pac_map->canmove(p)){
            pacy+=5;
            moving=true;

        }else{
            moving=false;
        }

        break;
    case 2:
        pacman->setDirection(direction);
        p.setX(pacx);
        p.setY(pacy-5);
        if(pac_map->canmove(p)){
            pacy-=5;
            moving=true;

        }else{
            moving=false;
        }

        break;
    }

    // this is so pacman can teleport through the side ports
    if(pacx<=0){
        pacx=450;
        pacy=230;
    }else if(pacx>=450){
        pacx=0;
        pacy=230;
    }

    //Set the coordinates

    pacman->setpacx(pacx);
    pacman->setpacy(pacy);


}


/// moving ghosts around the map
void Pacmanwindow::ghostsmove()
{
    QPoint p;

    if(!ghostmoving){
        // When the ghost hits a wall or can't move give them a random dirrection.
        ghostdir=(qrand()%4)+1;
    }else{

        //Changing direction dependant on where pacman is located
        if(ghostdir==4 && gosy<pacy || ghostdir==1 && gosy>pacy){
            if(ghostdir==1 && gosy>pacy){
                nextghostdir=2;
            }else if(ghostdir==4 &&gosy<pacy){
                nextghostdir=3;
            }

        }else if(ghostdir==3 && gosx<pacx || ghostdir==2 && gosx>pacx){
            if(ghostdir==2 && gosx>pacx){
                nextghostdir=1;
            }else if(ghostdir==3 && gosx<pacx){
                nextghostdir=4;
            }
        }

    }

// This keeps the ghosts moving if pacman is producing a trail 'canmove' Then setting the next direction the ghosts take
    // p.setX(gosx-5) is the amount of points it should move in the direction.

    if(nextghostdir!=ghostdir){
        switch(nextghostdir)
        {
        case 1:
            p.setX(gosx-5);
            p.setY(gosy);

            if(pac_map->canmove(p)){
                ghostdir=nextghostdir;
                nextghostdir=0;

            }

            break;

        case 4:
            p.setX(gosx+5);
            p.setY(gosy);
            if(pac_map->canmove(p)){
                ghostdir=nextghostdir;
                nextghostdir=0;

            }

            break;
        case 3:
            p.setX(gosx);
            p.setY(gosy+5);
            if(pac_map->canmove(p)){
                ghostdir=nextghostdir;
                nextghostdir=0;

            }

            break;
        case 2:
            p.setX(gosx);
            p.setY(gosy-5);
            if(pac_map->canmove(p)){
                ghostdir=nextghostdir;
                nextghostdir=0;

            }

            break;
        }

    }
    switch(ghostdir)
    {
    case 1:
        p.setX(gosx-5);
        p.setY(gosy);
        ghost->setDirection(ghostdir);

        if(pac_map->canmove(p)){
            gosx-=5;


            ghostmoving=true;

        }else{
            ghostmoving=false;
        }

        break;

    case 4:
        ghost->setDirection(ghostdir);
        p.setX(gosx+5);
        p.setY(gosy);
        if(pac_map->canmove(p)){
            gosx+=5;

            ghostmoving=true;

        }else{
            ghostmoving=false;
        }

        break;
    case 3:
        ghost->setDirection(ghostdir);
        p.setX(gosx);
        p.setY(gosy+5);
        if(pac_map->canmove(p)){
            gosy+=5;
            ghostmoving=true;

        }else{
            ghostmoving=false;
        }

        break;
    case 2:
        ghost->setDirection(ghostdir);
        p.setX(gosx);
        p.setY(gosy-5);
        if(pac_map->canmove(p)){
            gosy-=5;
            ghostmoving=true;

        }else{
            ghostmoving=false;
        }

        break;
    }


    if(gosx<=0){
        gosx=450;
        gosy=230;
    }else if(gosx>=450){
        gosx=0;
        gosy=230;
    }
    ghost->setgosx(gosx);
    ghost->setgosy(gosy);

}



void Pacmanwindow::ghostsmove1()
{
    QPoint p;



    if(!ghostmoving1){
        ghostdir1=(qrand()%4)+1; // when ghost colides with wall randomly select direction
    }else{
        //nextghostdir=(qrand()%4)+1;
        if(ghostdir1==4 && gosy1<pacy || ghostdir1==1 && gosy1>pacy){
            if(ghostdir1==1 && gosy>pacy){
                nextghostdir1=2;
            }else if(ghostdir1==4 &&gosy1<pacy){
                nextghostdir1=3;
            }

        }else if(ghostdir1==3 && gosx1<pacx || ghostdir1==2 && gosx1>pacx){
            if(ghostdir1==2 && gosx1>pacx){
                nextghostdir1=1;
            }else if(ghostdir1==3 && gosx1<pacx){
                nextghostdir1=4;
            }
        }

    }


    if(nextghostdir1!=ghostdir1){
        switch(nextghostdir1)
        {
        case 1:
            p.setX(gosx1-5);
            p.setY(gosy1);

            if(pac_map->canmove(p)){
                ghostdir1=nextghostdir1;
                nextghostdir1=0;

            }

            break;

        case 4:
            p.setX(gosx1+5);
            p.setY(gosy1);
            if(pac_map->canmove(p)){
                ghostdir1=nextghostdir1;
                nextghostdir1=0;

            }

            break;
        case 3:
            p.setX(gosx1);
            p.setY(gosy1+5);
            if(pac_map->canmove(p)){
                ghostdir1=nextghostdir1;
                nextghostdir1=0;

            }

            break;
        case 2:
            p.setX(gosx1);
            p.setY(gosy1-5);
            if(pac_map->canmove(p)){
                ghostdir1=nextghostdir1;
                nextghostdir1=0;

            }

            break;
        }

    }
    switch(ghostdir1)
    {
    case 1:
        p.setX(gosx1-5);
        p.setY(gosy1);
        ghost1->setDirection(ghostdir1);

        if(pac_map->canmove(p)){
            gosx1-=5;


            ghostmoving1=true;

        }else{
            ghostmoving1=false;
        }

        break;

    case 4:
        ghost1->setDirection(ghostdir1);
        p.setX(gosx1+5);
        p.setY(gosy1);
        if(pac_map->canmove(p)){
            gosx1+=5;

            ghostmoving1=true;

        }else{
            ghostmoving1=false;
        }

        break;
    case 3:
        ghost1->setDirection(ghostdir1);
        p.setX(gosx1);
        p.setY(gosy1+5);
        if(pac_map->canmove(p)){
            gosy1+=5;
            ghostmoving1=true;

        }else{
            ghostmoving1=false;
        }

        break;
    case 2:
        ghost1->setDirection(ghostdir1);
        p.setX(gosx1);
        p.setY(gosy1-5);
        if(pac_map->canmove(p)){
            gosy1-=5;
            ghostmoving1=true;

        }else{
            ghostmoving1=false;
        }

        break;
    }


    if(gosx1<=0){
        gosx1=450;
        gosy1=230;
    }else if(gosx1>=450){
        gosx1=0;
        gosy1=230;
    }
    ghost1->setgosx(gosx1);
    ghost1->setgosy(gosy1);

}

void Pacmanwindow::ghostsmove2()
{
    QPoint p;
    //int ir=qrand()%ballpoints.size();
    //    QVector<QPoint> points;





    if(!ghostmoving2){
        ghostdir2=(qrand()%4)+1;
    }else{
        //nextghostdir=(qrand()%4)+1;
        if(ghostdir2==4 &&gosy2<pacy || ghostdir2==1 && gosy2>pacy){
            if(ghostdir2==1 && gosy2>pacy){
                nextghostdir2=2;
            }else if(ghostdir2==4 &&gosy2<pacy){
                nextghostdir2=3;
            }

        }else if(ghostdir2==3 && gosx2<pacx || ghostdir2==2 && gosx2>pacx){
            if(ghostdir2==2 && gosx2>pacx){
                nextghostdir2=1;
            }else if(ghostdir2==3 && gosx2<pacx){
                nextghostdir2=4;
            }
        }

    }


    if(nextghostdir2!=ghostdir2){
        switch(nextghostdir2)
        {
        case 1:
            p.setX(gosx2-5);
            p.setY(gosy2);

            if(pac_map->canmove(p)){
                ghostdir2=nextghostdir2;
                nextghostdir2=0;

            }

            break;

        case 4:
            p.setX(gosx2+5);
            p.setY(gosy2);
            if(pac_map->canmove(p)){
                ghostdir2=nextghostdir2;
                nextghostdir2=0;

            }

            break;
        case 3:
            p.setX(gosx2);
            p.setY(gosy2+5);
            if(pac_map->canmove(p)){
                ghostdir2=nextghostdir2;
                nextghostdir2=0;

            }

            break;
        case 2:
            p.setX(gosx2);
            p.setY(gosy2-5);
            if(pac_map->canmove(p)){
                ghostdir2=nextghostdir2;
                nextghostdir2=0;

            }

            break;
        }

    }
    switch(ghostdir2)
    {
    case 1:
        p.setX(gosx2-5);
        p.setY(gosy2);
        ghost2->setDirection(ghostdir2);

        if(pac_map->canmove(p)){
            gosx2-=5;


            ghostmoving2=true;

        }else{
            ghostmoving2=false;
        }

        break;

    case 4:
        ghost2->setDirection(ghostdir2);
        p.setX(gosx2+5);
        p.setY(gosy2);
        if(pac_map->canmove(p)){
            gosx2+=5;

            ghostmoving2=true;

        }else{
            ghostmoving2=false;
        }

        break;
    case 3:
        ghost2->setDirection(ghostdir2);
        p.setX(gosx2);
        p.setY(gosy2+5);
        if(pac_map->canmove(p)){
            gosy2+=5;
            ghostmoving2=true;

        }else{
            ghostmoving2=false;
        }

        break;
    case 2:
        ghost2->setDirection(ghostdir2);
        p.setX(gosx2);
        p.setY(gosy2-5);
        if(pac_map->canmove(p)){
            gosy2-=5;
            ghostmoving2=true;

        }else{
            ghostmoving2=false;
        }

        break;
    }


    if(gosx2<=0){
        gosx2=450;
        gosy2=230;
    }else if(gosx2>=450){
        gosx2=0;
        gosy2=230;
    }
    ghost2->setgosx(gosx2);
    ghost2->setgosy(gosy2);

}

void Pacmanwindow::ghostsmove3()
{
    QPoint p,g;
    //int ir=qrand()%ballpoints.size();
    //    QVector<QPoint> points;






    if(!ghostmoving3){
        ghostdir3=(qrand()%4)+1;
    }else{
        //nextghostdir=(qrand()%4)+1;
        if(ghostdir3==4 &&gosy3<pacy || ghostdir3==1 && gosy3>pacy){
            if(ghostdir3==1 && gosy3>pacy){
                nextghostdir3=2;
            }else if(ghostdir3==4 &&gosy3<pacy){
                nextghostdir3=3;
            }

        }else if(ghostdir3==3 && gosx3<pacx || ghostdir3==2 && gosx3>pacx){
            if(ghostdir3==2 && gosx3>pacx){
                nextghostdir3=1;
            }else if(ghostdir3==3 && gosx3<pacx){
                nextghostdir3=4;
            }
        }

    }


    if(nextghostdir3!=ghostdir3){
        switch(nextghostdir3)
        {
        case 1:
            p.setX(gosx3-5);
            p.setY(gosy3);

            if(pac_map->canmove(p)){
                ghostdir3=nextghostdir3;
                nextghostdir3=0;

            }

            break;

        case 4:
            p.setX(gosx3+5);
            p.setY(gosy3);
            if(pac_map->canmove(p)){
                ghostdir3=nextghostdir3;
                nextghostdir3=0;

            }

            break;
        case 3:
            p.setX(gosx3);
            p.setY(gosy3+5);
            if(pac_map->canmove(p)){
                ghostdir3=nextghostdir3;
                nextghostdir3=0;

            }

            break;
        case 2:
            p.setX(gosx3);
            p.setY(gosy3-5);
            if(pac_map->canmove(p)){
                ghostdir3=nextghostdir3;
                nextghostdir3=0;

            }

            break;
        }

    }
    switch(ghostdir3)
    {
    case 1:
        p.setX(gosx3-5);
        p.setY(gosy3);
        ghost3->setDirection(ghostdir3);

        if(pac_map->canmove(p)){
            gosx3-=5;


            ghostmoving3=true;

        }else{
            ghostmoving3=false;
        }

        break;

    case 4:
        ghost3->setDirection(ghostdir3);
        p.setX(gosx3+5);
        p.setY(gosy3);
        if(pac_map->canmove(p)){
            gosx3+=5;

            ghostmoving3=true;

        }else{
            ghostmoving3=false;
        }

        break;
    case 3:
        ghost3->setDirection(ghostdir3);
        p.setX(gosx3);
        p.setY(gosy3+5);
        if(pac_map->canmove(p)){
            gosy3+=5;
            ghostmoving3=true;

        }else{
            ghostmoving3=false;
        }

        break;
    case 2:
        ghost3->setDirection(ghostdir3);
        p.setX(gosx3);
        p.setY(gosy3-5);
        if(pac_map->canmove(p)){
            gosy3-=5;
            ghostmoving3=true;

        }else{
            ghostmoving3=false;
        }

        break;
    }


    if(gosx3<=0){
        gosx3=450;
        gosy3=230;
    }else if(gosx3>=450){
        gosx3=0;
        gosy3=230;
    }
    ghost3->setgosx(gosx3);
    ghost3->setgosy(gosy3);

}

///// Keep ghosts in rectangles
void Pacmanwindow::moveghostsinrect3()
{
    if(gosx3==450/2+40 || gosx3==450/2-40){
        if(ghostdir3==4){
            ghostdir3=1;
        }else{
            ghostdir3=4;
        }
    }
    if(ghostdir3==4){

        gosx3-=2;

    }else{

        gosx3+=2;
    }




    ghost3->setgosx(gosx3);
    ghost3->setgosy(gosy3);
}
void Pacmanwindow::moveghostsinrect2()
{
    //this code will keep the ghosts in the rectangle, but when the updater goes through the loop it will release the gosx2-=5
    if(gosx2==450/2+40 || gosx2==450/2-40){
        if(ghostdir2==4){
            ghostdir2=1;
        }else{
            ghostdir2=4;
        }
    }
    if(ghostdir2==4){

        gosx2+=5;

    }else{

        gosx2-=5;
    }




    ghost2->setgosx(gosx2);
    ghost2->setgosy(gosy2);
}
void Pacmanwindow::moveghostsinrect1()
{
    if(gosx1==450/2+40 || gosx1==450/2-40){
        if(ghostdir1==4){
            ghostdir1=1;
        }else{
            ghostdir1=4;
        }
    }
    if(ghostdir1==4){

        gosx1+=5;

    }else{

        gosx1-=5;
    }




    ghost1->setgosx(gosx1);
    ghost1->setgosy(gosy1);
}
void Pacmanwindow::moveghostsinrect()
{
    if(gosx==450/2+40 || gosx==450/2-40){
        if(ghostdir==4){
            ghostdir=1;
        }else{
            ghostdir=4;
        }
    }
    if(ghostdir==4){

        gosx+=5;

    }else{

        gosx-=5;
    }




    ghost->setgosx(gosx);
    ghost->setgosy(gosy);
}


// This method is used to check for collisions with the ghosts and balls
void Pacmanwindow::checklost() // lost the game
{

    /// When all the points have been eaten start new game
    if(ballpoints.isEmpty() ){


        level += 1;
        starting += 1; // this means that difficulty won't be set again, so timer won't be increased.

        start_Game();

        int temp = hiscore;
        hiscore = temp;
    }
    // Checks for collisons between pacman and ghost
    if(pacman->collidesWithItem(ghost) ||
            pacman->collidesWithItem(ghost1) ||
            pacman->collidesWithItem(ghost2) ||
            pacman->collidesWithItem(ghost3)){


    // Checks for collision, when ghost is scared
        if(scared){
            // adds 100 points for each ghost
            score+=100;
            if(pacman->collidesWithItem(ghost)){
                // Resets ghost back to rectangle
                gosx=450/2;
                gosy=450/2;
                ghoststart=false;
            }
            if(pacman->collidesWithItem(ghost1)){
                gosx1=450/2;
                gosy1=450/2;
                ghoststart1=false;
            }
            if(pacman->collidesWithItem(ghost2)){
                gosx2=450/2;
                gosy2=450/2;
                ghoststart2=false;
            }
            if(pacman->collidesWithItem(ghost3)){
                gosx3=450/2;
                gosy3=450/2;
                ghoststart3=false;
            }
// Sound for the ghost being eaten
 //           waka->play(":/Sound/pacman_eatghost.wav");

        }else{
            // Sound for pacmans death :(

            if (lives > 0){


  //        waka->play(":/Sound/pacman_death.wav");

            lives -= 1;
            retry();}
            else{
// Adding the gameover scene text before end_Game(); because windows needs it to be declared first and makes for a smoother transistion
                scene->addItem(text);

                end_Game();

            }
        }


    }


}

// A method to avoke key pressing.

void Pacmanwindow::keyPressEvent(QKeyEvent *event)
{


// Pressing space will start the game

    if(event->key()==Qt::Key_Space)
    {
        if(!playing){
            start_Game();
            playing=true;
        }else{

        }
    }

    // This error catching stops pacman from being moving until the ghosts can move.

    if(gosx3==450/2){ // if the ghost is in the rectangle keep adding
        state++;

        //    pacman->advance();
    }
    if(state==4){ // when the state equals 2 release the ghosts(2 seconds as updater updates every 2 seconds)
        //        pacx=410/2;
        //        pacy=360;
        start=true;
        state=0;
    }
    if(!start){


    } else {

        // By adding values to direction or nextdirection it can work out which way pacman is going to move.
        switch(event->key())
        {

        case Qt::Key_Left:

            if(!moving){


                direction=1;

            }else{
                nextdirection=1;
            }

            break;
        case Qt::Key_Right:

            if(!moving){


                direction=4;

            }else{

                nextdirection=4;
            }

            break;
        case Qt::Key_Down:
            if(!moving){
                direction=3;
            }else{
                nextdirection=3;
            }



            break;
        case Qt::Key_Up:
            if(!moving){
                direction=2;
            }else{
                nextdirection=2;
            }
            break;

            /////////////////////asdw
            ///
        case Qt::Key_A:

            if(!moving){


                direction=1;

            }else{
                nextdirection=1;
            }

            break;
        case Qt::Key_D:

            if(!moving){


                direction=4;

            }else{

                nextdirection=4;
            }

            break;
        case Qt::Key_S:
            if(!moving){
                direction=3;
            }else{
                nextdirection=3;
            }



            break;
        case Qt::Key_W:
            if(!moving){
                direction=2;
            }else{
                nextdirection=2;
            }
            break;

            break;

        case Qt::Key_P:
            pause();
            break;

        case Qt::Key_C:
            on_controlsButton_clicked();
            break;

        case Qt::Key_Escape:
            break;


        default:
            break;
            //QFrame::keyPressEvent(event);


            // }
        }
    }

}



int scarestate=0;
int soundstate=0;
int timeGame;


// This updates the pacman with the use of timer connection
void Pacmanwindow::updater()
{




    // This will display the lives and level
    ui->livesLcdNumber_2->display(lives);
    ui->levelLcdNumber_2->display(level);
    checklost();
    pacman_move();

    //ballpoints loop to check when pacman collides with balls
    for(int i=0;i<ballpoints.size();i++){
        if(pacman->pacx==ballpoints[i].x() && pacman->pacy==ballpoints[i].y()){
            ballpoints.remove(i);
            score++;
            hiscore = score;
            text->score = score;
            // Setting the scores
            ui->highScroreLcdNumber_2->display(hiscore);
            ui->scoreLcdNumber_2->display(score);

// This stops the sound play on a constant loop giving a break to give a more realistic sounding through a loop created using the timer
            if(soundstate==0){
//				waka->play(":/Sound/pacman_chomp.wav");
				soundstate++;}
            else{soundstate++;if(soundstate==6){soundstate=0;}}


        }
    }
    // Powerball points used to charge a power up for pacman
    for(int i=0;i<Powerballpoints.size();i++){
        if(pacman->pacx==Powerballpoints[i].x() && pacman->pacy==Powerballpoints[i].y()){
            Powerballpoints.remove(i);
            if(scared){scarestate=0;}
            scared=true;
 //           waka->play(":/Sound/pacman_extrapac.wav");

        }
    }
    if(scared){
        ghost->is_Scared=true;
        ghost1->is_Scared=true;
        ghost2->is_Scared=true;
        ghost3->is_Scared=true;
        scarestate+=1;
        if(scarestate==1){ghoststimer->setInterval(150);} // how fast they move when blue
        if(scarestate==100){ // how long they stay blue for
            ghost->whiteb=true;
            ghost1->whiteb=true;
            ghost2->whiteb=true;
            ghost3->whiteb=true;

        }
        if(scarestate==150){
            scared=false; scarestate=0; ghoststimer->setInterval(75); // how fast they move when flashing white
            ghost->whiteb=false;
            ghost1->whiteb=false;
            ghost2->whiteb=false;
            ghost3->whiteb=false;
        }
    }else{
        ghost->is_Scared=false;
        ghost1->is_Scared=false;
        ghost2->is_Scared=false;
        ghost3->is_Scared=false;
    }





    // This takes the time and divdes it by 30 to give the best representitive of seconds.


    if (timeGame > -1)
    {
        timeGame++;

        ui->timeLcdNumber_2->display(timeGame/30);
    }

    text->timeElapsed = timeGame/30;

    text->name = this->name;
    text->difficulty = difficultyText;

    ball->setpoints(ballpoints);
    powerball->setpoints(Powerballpoints);
    pac_map->setballpoints(ballpoints);
    pac_map->setpowerballpoints(Powerballpoints);
    pac_map->fillpacpoints(pacx,pacy);
//    pacman->advance();
    ghost->advance();
    ghost1->advance();
    ghost2->advance();
    ghost3->advance();


    this->setFocus();
    scene->update(pac_map->boundingRect());

pacman->advance();


}

// This pauses the timer.
void Pacmanwindow::pause(){
    //if you are not playing do nothing.
    if (!playing)
        return;
    isPaused = !isPaused;
    if (isPaused) {

        timer->stop();
        ghoststimer->stop();


        text->paused=true;
        // Add pause to the screen
        scene->addItem(text);
        text->setZValue(6); // sets priorty high so it will show over the graphicscene

    } else {
        scene->removeItem(text);
        timer->start();
        ghoststimer->start();
    }

    update();



}

// This is an individual update for the ghosts, as they run on a seperate timer.
void Pacmanwindow::ghostupdater()// updates the ghosts posistion
{
    if(ghoststart || ghoststart1 || ghoststart2 || ghoststart3){
        if(ghoststart){ghostsmove();}
        if(ghoststart1){ghostsmove1();}
        if(ghoststart2){ghostsmove2();}
        if(ghoststart3){ghostsmove3();}
    }
    if(gosx3==450/2){ // if the ghost is in the rectangle keep adding
        state++;
    }
    if(state==4 || 0){ // when the state equals 2 release the ghosts(2 seconds as updater updates every 2 seconds)
        start=true;

        state=0;
    }
    if(!start){
        moveghostsinrect3();
        moveghostsinrect2();
        moveghostsinrect1();
        moveghostsinrect();

    }

    // This tells the ghost to leave the rectangle when set false, because otherwise it won't know too
    else if(!ghoststart3 || !ghoststart2 || !ghoststart1 || !ghoststart){
        QPoint p,p1,p2,p3;
        if(!ghoststart3){
            gosy3-=5;
            ghost3->setgosx(gosx3);
            ghost3->setgosy(gosy3);
            p3.setX(gosx3);
            p3.setY(gosy3);
            if(pac_map->pacpoints.contains(p3)){ghoststart3=true;}
        }

        if(!ghoststart2){
            gosy2-=5;
            ghost2->setgosx(gosx2);
            ghost2->setgosy(gosy2);
            p2.setX(gosx2);
            p2.setY(gosy2);
            if(pac_map->pacpoints.contains(p2)){ghoststart2=true;}
        }
        if(!ghoststart1){
            gosy1-=5;
            ghost1->setgosx(gosx1);
            ghost1->setgosy(gosy1);
            p1.setX(gosx1);
            p1.setY(gosy1);
            if(pac_map->pacpoints.contains(p1)){ghoststart1=true;}
        }
        if(!ghoststart){
            gosy-=5;
            ghost->setgosx(gosx);
            ghost->setgosy(gosy);
            p.setX(gosx);
            p.setY(gosy);
            if(pac_map->pacpoints.contains(p)){ghoststart=true;}
        }

    }
}


Pacmanwindow::~Pacmanwindow()
{
    delete ui;
}

// When pause button clicked pause the timer
void Pacmanwindow::on_pauseButton_clicked()// pauses the timer in the game
{
    pause();
}

// When controls buttons is clicked
void Pacmanwindow::on_controlsButton_clicked()// Change colour to black
{
// make sure the game is paused.
    if(isPaused == false){
        pause();
        // This opens a message box
        QPalette palette;
        palette.setColor(QPalette::Background, Qt::black);
        QMessageBox *controls = new QMessageBox;
        controls->setPalette(palette);
        controls->about(this,
                        tr("Controls"),
                        tr("<p align='center'><font><h1>Controls</h1><br>Press direction keys and aswd keys to move pacman across the screen.<br><br><br>Press ESC to exit application.<br><br><br>Press P to pause the game</font></p>"));




    }
}




