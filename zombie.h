/* 
 * File:   zombie.h
 * Author: Jake Braswell and Michael McCallum
 * 
 * Due on December 15th, 2017, 11:55 PM
 * Function:Header file for zombie
 * Input: None
 * Output: None
 */
#ifndef ZOMBIE_H
#define ZOMBIE_H
#include <cstdlib>
#include <iostream>


using namespace std;
/*prototypes for the zombie class
 * sets prototypes for the zombie class and inherits others from the human class
 */
class zombie: public human
{
public:
	zombie();
	zombie(int, int, bool);
	~zombie();
	int move(char);
	int attack;
};
#endif /* ZOMBIE>H */

