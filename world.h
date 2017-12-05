using namespace std;
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
		
		human Humans[8];
		zombie Zombies[9];
		char World[8][8];
		
	private:
		int numHumans;
		int numZombies;
};
