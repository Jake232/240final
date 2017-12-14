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
 x=-1;
 y=-1;
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
	
}

void human::setX(int _x)
{
 this->x= _x;
}

int human::getX()
{
 return this->x;
}

void human::setY(int _y)
{
 this->y = _y;
}

int human::getY()
{
 return this->y;
}

int human::move(char a){
	if(a==' ')
		return 1;
	else if(a=='Z')
		return 2;
	else
		return 0;
}

int human::getAttack(){
	return this->attack;
}

void human::setAttack(int a){
	this->attack = a;
}
