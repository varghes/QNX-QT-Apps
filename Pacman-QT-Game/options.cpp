
#include "options.h"
#include "ui_options.h"
#include "pacmanwindow.h"
#include <QDebug>


Options::Options(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Options)
{
    QLabel *image = new QLabel();
       image->setPixmap( QPixmap( "paclogo.jpg" ) );
       image->show();
    ui->setupUi(this);
    difficulty = 0;
    // if the toggle buttons not checked then warn
    // if text box

}

Options::~Options()
{
    delete ui;
}
// When start button is pressed, error handling, setting difficulty and name to fields in main class.

void Options::on_startButton_clicked()
{
    int temp = ui->nameText->toPlainText().size();
if (difficulty == 0 || ui->nameText->toPlainText() == "")
{
QMessageBox::warning(this,"Warning","You haven't filled in all criteria");
if (temp > 9)
{
    QMessageBox::warning(this,"Warning","Only 9 characters allowed in the name");

}
}
else {
Pacmanwindow *w = new Pacmanwindow;

QString nametemp = ui->nameText->toPlainText();

w->parseMessage(nametemp, difficulty);

    w->show();
    this->close();
}
}


// When a radio button is pressed set the current number to the point that was pressed.
void Options::on_easyButton_toggled(bool )
{
    difficulty = 1;
}

void Options::on_mediumButton_toggled(bool )
{
    difficulty = 2;
}

void Options::on_hardButton_toggled(bool )
{
    difficulty = 3;
}
