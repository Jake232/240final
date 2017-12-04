/* 
 * File:   human.h
 * Author: Michael McCallum
 * 
 * Due on November 17, 2017, 11:55 PM
 * Function:Header file for human
 * Input: None
 * Output: None
 */


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
	bool move(char);


public:
	bool dead;
	int x;
	int y;

};
	
	
 
