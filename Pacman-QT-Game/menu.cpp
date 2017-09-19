#include "menu.h"
#include "ui_menu.h"
//#include "Pacmanwindow.h"
#include "options.h"
#include <QCloseEvent>
#include <QMessageBox>
#include <QFile>
#include <QFileInfo>
#include <QTextStream>
#include <QFileDialog>

Menu::Menu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);

    QPalette q;
    q.setColor(QPalette::Background, Qt::black);
this->setPalette(q);
}

Menu::~Menu()
{
    delete ui;
}

void Menu::on_startButton_clicked()
{
Options *m = new Options;
m->show();
this->window()->close();
}




void Menu::on_loadButton_clicked()
{

//w->show();
//this->close();

}

void Menu::on_optionsButton_clicked()
{
    Options *m = new Options;
m->show();
this->window()->close();
}

void Menu::on_exitButton_clicked()
{
this->window()->close();
}


