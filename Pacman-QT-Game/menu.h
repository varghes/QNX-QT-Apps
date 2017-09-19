#ifndef MENU_H
#define MENU_H

#include <QWidget>
#include "Pacmanwindow.h"

namespace Ui {
class Menu;
}

class Menu : public QWidget
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = 0);
    ~Menu();

private slots:
    void on_startButton_clicked();
    void on_loadButton_clicked();

    void on_optionsButton_clicked();

    void on_exitButton_clicked();

private:
    Ui::Menu *ui;

    void loadFile(const QString &);
//    void setFileName(const QString &);

    QString m_fileName;

};

#endif // MENU_H
