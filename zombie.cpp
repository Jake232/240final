/* 
 * File:   zombie.cpp
 * Author: Jake Braswell and Michael McCallum
 * 
 * Due on December, 2017, 11:55 PM
 * Function:Body file for zombie
 * Input: None
 * Output: None
 */

# include "human.h"
# include "zombie.h"
/*Default constructor
  sets x, y, and boolean 'dead' to default values
*/
zombie::zombie()
{
x=-1;
y=-1;
}
/*Constructor
takes in an integer value and node
sets current node data to value and sets link to the next node
*/
zombie::zombie(int _x, int _y, bool _dead)
{
x=_x;
y=_y;
dead=_dead;
}
/*Deconstructor
  clears memory
*/
zombie::~zombie()
{
	
}
/*move function
 * takes in a character
 * if the space in the grid is open, it allows the zombie to move, if the space is occupied by a human, it triggers the attack system
*/
int zombie::move(char a)
{
if(a==' ')
	return 1;
else if(a=='H')
	return 2;
else
	return 0;

}

