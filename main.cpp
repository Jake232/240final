/* 
 * File:   main.cpp
 * Author: Jake Braswell and Michael McCallum
 * 
 * Due on December 15th, 2017, 11:55 PM
 * Function: 
 * Input: None
 * Output: None
 */

#include<ctime>
#include<unistd.h>
#include<stdlib.h>

#include "world.cpp"

int main(int argc, char **argv){
//Allows it to have new random numbers on each run
srand(time(NULL));

//Creates variable god which can call all of the world functions
world god;

//Variables to check if any humans are alive
bool allDead = false;

//Checks if all zombies have been defeated
bool noZombies = false;

//Variable for user exit
bool uexit = false;

//Keep track of number of days
int day = 0;

//Creates the board and places 8 humans a zombie
god.setUp();

//While theres at least one human or zombie alive and tthe user has not chose to exit
while(!allDead && !uexit && !noZombies){
	cout << "Day: " << day << endl;

	god.refreshWorld();
	god.print();
	
	//Move all Humans
	for(int i=0; i<8; i++){
		god.refreshWorld();
		if(god.Humans[i].getX()!=-1)
			god.move(god.Humans[i]);
	}
	
	//Refreshes the world and wiats before moving zombies
	god.refreshWorld();
	usleep(0.25*1000000);
	
	//Move all Zombies
	for(int i=0; i<9; i++){
		god.refreshWorld();
		if(god.Zombies[i].getX()!=-1)
			god.move(god.Zombies[i]);
	}
	
	//Checks to see if any Humans are still alive
	allDead=true;
	for(int i=0; i<8; i++){
		if(god.Humans[i].getX()!=-1)
			allDead = false;
	}
	
	//Check to see if there are zombies left
	noZombies = true;
	for(int i=0; i<9; i++){
		if(god.Zombies[i].getX()!=-1){
			noZombies = false;
		}
	}
	
	//Uncomment if you want user input between each day
	/*cout << "Go to next day?(y,n)" << endl;
	char user;
	cin >> user;
	if(user == 'n')
		uexit=true;*/
	
	//Increases the day count
	++day;
	
	//Prints a bunch of new lines to look like the board is just refreshing
	for(int i=0; i<100; i++)
		cout << endl;
}

//If all the humans are dead
if(allDead){
cout << "Number of days to kill all humans: " << day << endl;
cout << endl << "Final Board" << endl;
god.refreshWorld();
god.print();
}

//If all of the zombies have been defeated
if(noZombies){
cout << "Number of days to kill all zombies: " << day << endl;
cout << endl << "Final Board" << endl;
god.refreshWorld();
god.print();
}

}
