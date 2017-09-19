#include <QtGui>
#include "calc.h"

calc::calc(QWidget *parent) :
    QMainWindow(parent)
{
    setupUi(this);

    setFixedSize(sizeHint());

    clearall();

    connect (Button1,SIGNAL(clicked()),this,SLOT(add1()));
    connect (Button2,SIGNAL(clicked()),this,SLOT(add2()));
    connect (Button3,SIGNAL(clicked()),this,SLOT(add3()));
    connect (Button4,SIGNAL(clicked()),this,SLOT(add4()));
    connect (Button5,SIGNAL(clicked()),this,SLOT(add5()));
    connect (Button6,SIGNAL(clicked()),this,SLOT(add6()));
    connect (Button7,SIGNAL(clicked()),this,SLOT(add7()));
    connect (Button8,SIGNAL(clicked()),this,SLOT(add8()));
    connect (Button9,SIGNAL(clicked()),this,SLOT(add9()));
    connect (Button0,SIGNAL(clicked()),this,SLOT(add0()));
    connect (backButton,SIGNAL(clicked()),this,SLOT(delnum()));
    connect (pointButton,SIGNAL(clicked()),this,SLOT(insertpoint()));
    connect (plusButton,SIGNAL(clicked()),this,SLOT(plus()));
    connect (minusButton,SIGNAL(clicked()),this,SLOT(minus()));
    connect (multiplyButton,SIGNAL(clicked()),this,SLOT(multiply()));
    connect (divideButton,SIGNAL(clicked()),this,SLOT(divide()));
    connect (equalButton,SIGNAL(clicked()),this,SLOT(equal()));
    connect (CButton,SIGNAL(clicked()),this,SLOT(clearall()));
    connect (actionAbout_Qt,SIGNAL(triggered()),this,SLOT(about()));
    connect (actionExit,SIGNAL(triggered()),this,SLOT(close()));
    connect (pmButton,SIGNAL(clicked()),this,SLOT(togglepm()));
}

void calc::about() {QApplication::aboutQt();}
void calc::add1() {addnumber('1');}
void calc::add2() {addnumber('2');}
void calc::add3() {addnumber('3');}
void calc::add4() {addnumber('4');}
void calc::add5() {addnumber('5');}
void calc::add6() {addnumber('6');}
void calc::add7() {addnumber('7');}
void calc::add8() {addnumber('8');}
void calc::add9() {addnumber('9');}
void calc::add0() {addnumber('0');}

void calc::initnum() {num1 = 0;num2 = MAX+1;}

void calc::error(int errorno)
{
    isError = true;
    switch (errorno)
    {
    case 1:
    {
        shownumber = "Out of boundary.";
        refresh();
        break;
    }
    case 2:
    {
        shownumber = "Divide by Zero.";
        refresh();
        break;
    }
    }
}

void calc::togglepm()
{
    if (!added)
    {
        shownumber = "0";
        point = ".";
        refresh();
    }
    if ((shownumber == "0") || (shownumber == "0.")) return;
    if (shownumber[0] == '-')
    {
        shownumber.remove( 0 , 1 );
    }
    else
    {
        shownumber = '-' + shownumber;
    }
    refresh();
}

void calc::cast()
{
    if (!added) {lastop = op;return;}
    if (!first) equal(); else
    {
        num1 = shownumber.toDouble();
        num2 = num1;
        first = false;
        lastop = op;
    }
    added = false;
}

void calc::plus()
{
    op = 1;
    cast();
}

void calc::minus()
{
    op = 2;
    cast();
}

void calc::multiply()
{
    op = 3;
    cast();
}

void calc::divide()
{
    op = 4;
    cast();
}

void calc::equal()
{
    if (first) return;
    double tmp = 0;
    if (added) num2 = shownumber.toDouble();
    if ((num2 == 0) && (op == 4)) {error(2);return;}
    switch (lastop)
    {
    case 1: {tmp = num1 + num2; break;}
    case 2: {tmp = num1 - num2; break;}
    case 3: {tmp = num1 * num2; break;}
    case 4: {tmp = num1 / num2; break;}
    }
    if ((tmp > MAX) || (tmp < -MAX)) {error(1);return;}
    shownumber = QString::number(tmp);
    num1 = tmp; lastop = op;
    if (shownumber.indexOf('.') == -1) point = '.'; else point = "";
    refresh();
    added = false;
    first = true;
}

void calc::refresh()
{
    lineEdit->setText(shownumber + point);
}


void calc::clearall()
{
    initnum();
    shownumber = '0';
    point = '.';
    first = true;
    isError = false;
    added = false;
    refresh();
}

void calc::insertpoint()
{
    if (point == "") return;
    point = "";
    addnumber('.');
}

void calc::delnum()
{
    if (!added)
    {
        first = true;
    }
    int lastpoint = shownumber.length() - 1;
    if (lastpoint<0)
    {
        clearall();
        return;
    }
    if (shownumber[lastpoint]=='.')  {point = '.';}
    shownumber.remove(lastpoint,1);
    if (shownumber.length() == 0)
    {
        shownumber = "0";
        point = '.';
    }
    refresh();
}

void calc::addnumber(QChar number)
{
    if (!added)
    {
        added = true;
        shownumber = '0';
        if (number != '.') point = ".";
    }
    if (shownumber == "0")
    {
        if (number == '.') shownumber = "0."; else shownumber = (QString)number;
    }
    else shownumber.append(number);
    refresh();
}
