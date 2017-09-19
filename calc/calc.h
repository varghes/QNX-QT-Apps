#ifndef CALC_H
#define CALC_H

#include <QMainWindow>
#include <QtGlobal>
#include "ui_calc.h"

#define MAX 932838457459459

class calc : public QMainWindow , public Ui::calc
{
    Q_OBJECT
    
public:
    calc(QWidget *parent=0);
    QString shownumber;
    QString point;
    double num1,num2;
    bool first,isError,added;
    int op,lastop;

private:
    void initnum();
    void addnumber(QChar);
    void refresh();
    void error(int);
    void cast();

private slots:
    void add1();
    void add2();
    void add3();
    void add4();
    void add5();
    void add6();
    void add7();
    void add8();
    void add9();
    void add0();
    void delnum();
    void insertpoint();
    void clearall();
    void plus();
    void minus();
    void multiply();
    void divide();
    void equal();
    void about();
    void togglepm();

};

#endif // CALC_H
