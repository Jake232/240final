using namespace std;
#include<vector>
#include "human.cpp"
#include "zombie.cpp"
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
