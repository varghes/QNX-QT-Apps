#ifndef MYBUTTON_H
#define MYBUTTON_H


#include<QPushButton>

class MyButton:public QPushButton{
public:
MyButton();
bool isclicked;
public slots:
bool clicked();

};

#endif // MYBUTTON_H
