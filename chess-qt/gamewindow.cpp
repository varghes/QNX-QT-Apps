#include "gamewindow.h"
#include "ui_gamewindow.h"

GameWindow::GameWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);
    setWindowTitle(trUtf8("Chess"));

    mkBoard();

    connect(ui->stopButton,SIGNAL(clicked()),SLOT(deleteLater()));
}

GameWindow::~GameWindow()
{
    emit stop();
    delete ui;
}

void GameWindow::mkBoard()
{
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0, 0, 800, 800);
    scene->setBackgroundBrush(Qt::lightGray);
    ui->graphicsView->setScene(scene);


    bool isWhite = true;  //Рисуем  игральну доску
    for(int y = 0; y < 800; y += 100)
    {
        for(int x = 0; x < 800; x += 100)
        {
            QBrush brush;
            if(isWhite) brush = QBrush(Qt::white);
            else brush = QBrush(Qt::gray);
            scene->addRect(x, y, 100, 100, QPen(Qt::black), brush);

            if(isWhite) isWhite = false;
            else isWhite = true;
        }
        if(isWhite) isWhite = false;
        else isWhite = true;
    }

//расставляем фигуры
      int posX = 0;
      int posY = 0;

      for(posX = 0; posX<800; posX += 700)
      {
          figure = scene->addPixmap(QPixmap("://images/black_rook.png"));
          figure->setPos(posX, posY);
          if(figure) blackFigures.append(figure);
          figure->setFlag(QGraphicsItem::ItemIsMovable);
          figure->setData(0, "Rook");
      }

      posX = 100;
      for(posX = 100; posX<800; posX += 500)
      {
      figure = scene->addPixmap(QPixmap("://images/black_horse.png"));
      figure->setPos(posX, posY);
      if(figure) blackFigures.append(figure);
      figure->setFlag(QGraphicsItem::ItemIsMovable);
      figure->setData(0,"Horse");
      }

      posX = 200;
      for(posX=200; posX<800; posX +=300)
      {
      figure = scene->addPixmap(QPixmap("://images/black_bishop.png"));
      figure->setPos(posX, posY);
      if(figure) blackFigures.append(figure);
      figure->setFlag(QGraphicsItem::ItemIsMovable);
      figure->setData(0, "Bishop");
      }

      posX = 300;
      figure = scene->addPixmap(QPixmap("://images/black_queen.png"));
      figure->setPos(posX, posY);
      if(figure) blackFigures.append(figure);
      figure->setFlag(QGraphicsItem::ItemIsMovable);
      figure->setData(0, "Queen");

      posX = 400;
      figure = scene->addPixmap(QPixmap("://images/black_king.png"));
      figure->setPos(posX, posY);
      if(figure) blackFigures.append(figure);
      figure->setFlag(QGraphicsItem::ItemIsMovable);
      figure->setData(0, "King");

//расставляем белые

      posX = 0;
      posY = 700;

      for(posX = 0; posX<800; posX += 700)
      {
      figure = scene->addPixmap(QPixmap("://images/white_rook.png"));
      figure->setPos(posX, posY);
      if(figure) whiteFigures.append(figure);
      figure->setFlag(QGraphicsItem::ItemIsMovable);
      figure->setData(0, "Rook");
      }

      posX = 100;
      for(posX = 100; posX<800; posX += 500)
      {
      figure = scene->addPixmap(QPixmap("://images/white_horse.png"));
      figure->setPos(posX, posY);
      if(figure) whiteFigures.append(figure);
      figure->setFlag(QGraphicsItem::ItemIsMovable);
      figure->setData(0, "Horse");
      }

      posX = 200;
      for(posX=200; posX<800; posX +=300)
      {
      figure = scene->addPixmap(QPixmap("://images/white_bishop.png"));
      figure->setPos(posX, posY);
      if(figure) whiteFigures.append(figure);
      figure->setFlag(QGraphicsItem::ItemIsMovable);
      figure->setData(0, "Bishop");
      }

      posX = 300;
      figure = scene->addPixmap(QPixmap("://images/white_queen.png"));
      figure->setPos(posX, posY);
      if(figure) whiteFigures.append(figure);
      figure->setFlag(QGraphicsItem::ItemIsMovable);
      figure->setData(0, "Queen");

      posX = 400;
      figure = scene->addPixmap(QPixmap("://images/white_king.png"));
      figure->setPos(posX, posY);
      if(figure) whiteFigures.append(figure);
      figure->setFlag(QGraphicsItem::ItemIsMovable);
      figure->setData(0, "King");

      posY = 100;
      for(posX = 0; posX < 800; posX += 100)
      {
          figure = scene->addPixmap(QPixmap("://images/black_pawn.png"));
          figure->setPos(posX, posY);
          if(figure) blackFigures.append(figure);
          figure->setFlag(QGraphicsItem::ItemIsMovable);
          figure->setData(0, "Pawn");
      }

      posY = 600;
      for(posX = 0; posX < 800; posX += 100)
      {
          figure = scene->addPixmap(QPixmap("://images/white_pawn.png"));
          figure->setPos(posX, posY);
          if(figure) whiteFigures.append(figure);
          figure->setFlag(QGraphicsItem::ItemIsMovable);
          figure->setData(0, "Pawn");
      }


}


void GameWindow::closeEvent(QCloseEvent *event) //обрабатываем событие закрытия окна игры
{
    int r = QMessageBox::warning(this, "Attention !",QString("You really want to close the game?"),
                                        QMessageBox::Yes ,
                                        QMessageBox::No | QMessageBox::Default);
    if (r == QMessageBox::No)  event->ignore();   //игнорируем закрытие
    if (r == QMessageBox::Yes) event->accept();   //подтверждаем событие и закрываем приложение
}
