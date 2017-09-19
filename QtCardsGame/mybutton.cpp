#include <mybutton.h>



bool MyButton::clicked()
{
    isclicked = true;
    return isclicked;
}

 MyButton::MyButton()
 {
	 isclicked = false;
 }