#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle(trUtf8("Chess"));
    setWindowIcon(QIcon("://images/black_king.png"));
    moveToCenter();
    mkDir();

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    scene->setBackgroundBrush(Qt::lightGray);

    ellipse = scene->addEllipse(0,0,150,150,QPen(Qt::gray),QBrush(Qt::white));
    saver = scene->addPixmap(QPixmap("://images/black_king.png"));
    saver->setPos(25, 25);

    connect(ui->loadButton, SIGNAL(clicked()),SLOT(showLoad())); //показываем окно загрузки сохраненной игры
    connect(ui->loadButton, SIGNAL(clicked()),SLOT(hide())); //делаем невидимым главное окно

    connect(ui->newButton, SIGNAL(clicked()),SLOT(showNew()));
    connect(ui->newButton, SIGNAL(clicked()),SLOT(hide()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showLoad() //загружаем диалог выбора сохранений
{
    this->hide();
    loadw = new LoadWindow(this);
    loadw->show();
    connect(loadw,SIGNAL(stop()),this,SLOT(show()));
}

void MainWindow::showNew() //загружаем окно игры
{
    this->hide();
    gamew = new GameWindow(this);
    gamew->resize(QSize(900,900));
    gamew->show();
    connect(gamew,SIGNAL(stop()),this,SLOT(show()));
}

void MainWindow::moveToCenter()
{
    QDesktopWidget desktop;
    QRect rect = desktop.availableGeometry(desktop.primaryScreen()); // прямоугольник с размерами экрана
    QPoint center = rect.center(); //координаты центра экрана
    center.setX(center.x() - (this->width()/2));  // учитываем половину ширины окна
    center.setY(center.y() - (this->height()/2));  // .. половину высоты
    move(center);
}

void MainWindow::mkDir()
{
    QDir::currentPath();
    if (QDir().exists("save"))       //если папка уже создана
        return;                      //выходим из метода
    else                             //если папка отсутствует
    {
      if (QDir().mkdir("save"))      //создаем
         return;                     //и выходим из метода
      else                           //если при создании возникла ошибка выводим диалоговое окно с сообщением.
          QMessageBox::warning(this, "Error",QString("Could not create a save directory !"), QMessageBox::Ok);
    }

}
