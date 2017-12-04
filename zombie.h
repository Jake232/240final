/* 
 * File:   zombie.h
 * Author: Michael McCallum
 * 
 * Due on November 17, 2017, 11:55 PM
 * Function:Header file for zombie
 * Input: None
 * Output: None
 */
#ifndef ZOMBIE_H
#define ZOMBIE_H
#include <cstdlib>
#include <iostream>


using namespace std;

class zombie: public human
{
public:
	zombie();
	zombie(int, int, bool);
	~zombie();
	bool move(char);
};
#endif /* ZOMBIE>H */
