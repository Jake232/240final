/* 
 * File:   human.h
 * Author: Michael McCallum
 * 
 * Due on November 17, 2017, 11:55 PM
 * Function:Header file for human
 * Input: None
 * Output: None
 */

#ifndef HUMAN_H
#define HUMAN_H
#include <cstdlib>
#include <iostream>


using namespace std;

class human
{
public:
	human();
	human(int, int, bool);
	~human();
	
	int getX();
	int getY();
	void setX(int);
	void setY(int);
	int move(char);
	int getAttack();
	void setAttack(int);
	
	bool dead;
	int x;
	int y;
	int attack;
};
#endif /* HUMAN_H */
	
	
 
