#include "loadwindow.h"
#include "ui_loadwindow.h"

LoadWindow::LoadWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoadWindow)
{
    ui->setupUi(this);
    setWindowTitle(trUtf8("Chess"));
    connect(ui->cancelButton,SIGNAL(clicked()),SLOT(deleteLater()));

//пока отображаем содержимое папки запуска, потом будем отображать save
    QFileSystemModel *model = new QFileSystemModel(this);
    model->setRootPath(QDir::currentPath());
    ui->listView->setModel(model);
    ui->listView->setRootIndex(model->index(QDir::currentPath()));
}

LoadWindow::~LoadWindow()
{
    emit stop(); //испускаем сигнал о закрытии
    delete ui;
}
