/* 
 * File:   zombie.cpp
 * Author: Michael McCallum
 * 
 * Due on November 17, 2017, 11:55 PM
 * Function:Body file for zombie
 * Input: None
 * Output: None
 */

# include "human.h"
# include "zombie.h"

zombie::zombie()
{
x=-1;
y=-1;
}

zombie::zombie(int _x, int _y, bool _dead)
{
x=_x;
y=_y;
dead=_dead;
}

zombie::~zombie()
{
	
}

int zombie::move(char a)
{
if(a==' ')
	return 1;
else if(a=='H')
	return 2;
else
	return 0;

}
