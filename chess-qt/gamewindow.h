#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QDialog>
#include <QtCore>
#include <QtGui>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QMessageBox>

namespace Ui {
class GameWindow;
}

class GameWindow : public QDialog
{
    Q_OBJECT

    QVector<QGraphicsPixmapItem*> whiteFigures;
    QVector<QGraphicsPixmapItem*> blackFigures;

public:
    explicit GameWindow(QWidget *parent = 0);
    ~GameWindow();

signals:
     void stop();

private slots:
    void mkBoard();

protected:
    void closeEvent(QCloseEvent* event);

private:
    Ui::GameWindow *ui;
    QGraphicsScene *scene;
    QGraphicsPixmapItem *figure;
};

#endif // GAMEWINDOW_H
