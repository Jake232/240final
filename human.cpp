/* 
 * File:   human.cpp
 * Author: Michael McCallum
 * 
 * Due on November 17, 2017, 11:55 PM
 * Function:Body file for human
 * Input: None
 * Output: None
 */

# include "human.h"
# include "zombie.h"

human::human()
{
 x=0;
 y=0;
 dead = false;
}

human::human(int _x, int _y, bool _dead)
{
 x=_x;
 y=_y;
 dead=_dead;
}


human::~human()
{
 x=0;
 y=0;
}

void human::setX(int _x)
{
 x=_x;
}

int human::getX()
{
 return x;
}

void human::setY(int _y)
{
 x=_y;
}

int human::getY()
{
 return y;
}

bool human::move(char a)
{
if(a == 'h')
return false;
else
return true;
}
