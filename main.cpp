#include "world.cpp"
int main(int argc, char **argv){
world god;
//Variables for keeping track of the number of days and if any humans are alive
bool allDead = false;
int day = 0;

//Creates the board and places 8 humans a zombie
god.setUp();

//While theres at least one human alive
while(!allDead){
	cout << "Day: " << day << endl;

	god.refreshWorld();
	god.print();

	//Move all Zombies
	for(int i=0; i<9; i++){
		if(god.Zombies[i].getX()!=-1)
			god.move(god.Zombies[i]);
	}

	//Move all Humans
	for(int i=0; i<8; i++){
		if(god.Humans[i].getX()!=-1)
			god.move(god.Humans[i]);
	}

	//Checks to see if any Humans are still alive
	allDead=true;
	for(int i=0; i<8; i++){
		if(god.Humans[i].getX()!=-1)
			allDead = false;
	}

	++day;
	}
cout << "Number of days to kill all humans: " << day-1 << endl;
cout << endl << "Final Board" << endl;
god.refreshWorld();
god.print();
}
