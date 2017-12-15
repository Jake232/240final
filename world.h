/* 
 * File:   world.h
 * Author: jake Braswell and Michael McCallum
 * 
 * Due on December 15th, 2017, 11:55 PM
 * Function:Creates a node with data and a link to the next node to be used in the linked list
 * Input: None
 * Output: None
 */

using namespace std;
#include<vector>
#include "human.cpp"
#include "zombie.cpp"
/*prototypes for world class
 * sets the prototypes for the world class, keeps numHumans and numZombies private so they can't be changed by the user
 */
class world{
	public:
		world();
		void move(human&);
		void move(zombie&);
		void print();
		void setUp();
		bool anyHumansHere(int,int);
		bool anyZombiesHere(int,int);
		void refreshWorld();
		void zombify(human&);
		char getSpot(int,int);
		void fight(human&,int,int);
		void fight(zombie&,int,int,int,int);
		void removeZombie(zombie&,int);
		
		vector<human> Humans;
		vector<zombie> Zombies;
		char World[8][8];
		
	private:
		int numHumans;
		int numZombies;
};

