/* 
 * File:   human.cpp
 * Author: Jake Braswell and Michael McCallum
 * 
 * Due on December 15th, 2017, 11:55 PM
 * Function:List and defines the constructors and functions
 * Input: None
 * Output: None
 */

# include "human.h"
# include "zombie.h"
/*Default constructor
  sets x, y, and boolean 'dead' to default values
*/
human::human()
{
 x=-1;
 y=-1;
 dead = false;
}
/*Constructor
takes in two integer values and a boolean
sets current node data to value and sets link to the next node
*/
human::human(int _x, int _y, bool _dead)
{
 x=_x;
 y=_y;
 dead=_dead;
}
/*Deconstructor
  clears memory
*/
human::~human()
{
	
}
/*setX Function
 * takes in an integer
 * sets the x axis value for human on the grid
*/
void human::setX(int _x)
{
 this->x= _x;
}
/*getX function
 * takes in no parameters
 * gets the value of the x
*/
int human::getX()
{
 return this->x;
}
/*setY function
 * takes in an integer
 * sets the y axis value for human on the grid
*/
void human::setY(int _y)
{
 this->y = _y;
}
/*getY function
 * takes in no parameters
 * gets the y value
*/
int human::getY()
{
 return this->y;
}
/*move function
 * takes in a character
 * if the space in the grid is open, it allows the human to move, if the space is occupied by a zombie, it triggers the attack system
*/
int human::move(char a){
	if(a==' ')
		return 1;
	else if(a=='Z')
		return 2;
	else
		return 0;
}
/*getAttack function
 * returns the value of attack
*/
int human::getAttack(){
	return this->attack;
}
/*setAttack
 * takes in an integer
 * sets the attack to integer a
  clears memory
*/
void human::setAttack(int a){
	this->attack = a;
}

