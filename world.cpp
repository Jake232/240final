/* 
 * File:   world.cpp
 * Author: Jake Braswell and Michael McCallum
 * 
 * Due on December 15th, 2017, 11:55 PM
 * Function:Creates a node with data and a link to the next node to be used in the linked list
 * Input: None
 * Output: None
 */
#include "world.h"
#include<vector>
#include<stdlib.h>
#include<iostream>
using namespace std;
/*Default construtor for World class
 * sets numHumans and numZombies default to 0
 * sets the original size of humans to 8 and zombies to 9
 */
world::world(){
	numHumans = 0;
	numZombies = 0;
	Humans.resize(8);
	Zombies.resize(9);
}
/*Move Function
 * Takes in a human
 * Generates a random move
 * Based on what the move function in human it Moves, stays in place, or fights a zombie
 */
void world::move(human &h){
		
		if(!h.dead){
		int direction = rand()&4-1;
		
		int x = h.getX();
		int y = h.getY();
		
		if(direction == 0){
			if(x!=7){
				x+=1;
				int space = h.move(World[x][y]);
				
				if(space==1){
					h.setX(x);
					World[x][y]='H';
				}
				
				else if(space==2)
					fight(h,x,y);
			}
		}
		else if(direction == 1){
			if(y!=7){
			y+=1;
			int space = h.move(World[x][y]);
			
			if(space == 1){
					h.setY(y);
					World[x][y]='H';
			}
			
			else if(space == 2)
					fight(h,x,y);
			}
		}
		else if(direction == 2){
			if(x!=0){
				x-=1;
				int space = h.move(World[x][y]);
				
				if(space==1){
					h.setX(x);
					World[x][y]='H';
				}
				
				else if(space==2)
					fight(h,x,y);
			}
		}
		else{
			if(y!=0){
				y-=1;
				
				int space = h.move(World[x][y]);
				
				if(space==1){
					h.setY(y);
					World[x][y]='H';
				}
				
				else if(space==2)
					fight(h,x,y);
			}
		}
	}
}

/*fight
 * Takes in a human and two integers
 * It locates the human and zombie in their respected arrays
 * Once found if the zombies attack is less than the humans it is defeated
 * Otherwise the human is turned into a zombie
 */ 
void world::fight(human &h, int x, int y){
	cout << "FIGHT!" << endl;
	zombie temp;
	human temp2;
	int zPos=-1;
	int hPos=-1;
	for(int i=0; i<9; i++){
		if(Zombies[i].getX()==x && Zombies[i].getY()==y){
			temp = Zombies[i];
			zPos = i;
		}
	}
	if(zPos==-1){
		cout << "ERROR in locating Zombie" << endl;
		exit(1);
	}
	
	for(int i=0; i<8; i++){
		if(Humans[i].getX()==h.getX()&&Humans[i].getY()==h.getY()){
			temp2 = Humans[i];
			hPos = i;
		}
	}
	if(hPos==-1||temp2.getAttack()<1||temp2.getAttack()>100){
		cout << "ERROR in locating Human" << endl;
		cout << "X: " << h.getX() << " Y: " << h.getY() << endl;
		exit(1);
	}
	
	cout << "A zombie with an attack of " << temp.getAttack() << " fights a human with an attack of " << temp2.getAttack() << endl;
	if(temp2.getAttack()<temp.getAttack())
		zombify(h);
	else
		removeZombie(temp,zPos);
}
/*zombify function
 * Takes in a human
 * Removes the human from the array and places a zomby in the place of the human with all of its old data
 */
void world::zombify(human &h){
	cout << "A human has turned into a zombie" << endl;
	
	int x = h.getX();
	int y = h.getY();
	int a = h.getAttack();
	
	h.setX(-1);
	h.setY(-1);
	
	if(numZombies>8)
		Zombies.resize(12);
	
	Zombies[numZombies].setX(x);
	Zombies[numZombies].setY(y);
	Zombies[numZombies].setAttack(a);
	numZombies++;
	
	World[x][y]='Z';
}
/*removeZombie
 * Takes in a zombie and an integer i
 * If a zombie loses a fight between the human and zombie then it is removed from the grid by setting it's values to -1
 */
void world::removeZombie(zombie &z, int i){
	cout << "A zombie has been defeated" << endl;
		Zombies[i].x=-1;
		Zombies[i].y=-1;
		z.setX(-1);
		z.setY(-1);
}

/*Move Function
 * Takes in a zombie
 * Generates a random move
 * Based on what the move function in zombie it Moves, stays in place, or fights a zombie
 */
void world::move(zombie &z){
	int direction = rand()&4-1;
		int x = z.getX();
		int y = z.getY();
		if(direction == 0){
			if(x!=7){
				x+=1;
				int space = z.move(World[x][y]);
				
				if(space==1){
					z.setX(x);
					World[x][y]='Z';
				}
				
				else if(space==2)
					fight(z,x,y,(x-1),y);
			}
		}
		else if(direction == 1){
			if(y!=7){
			y+=1;
				int space = z.move(World[x][y]);
				
				if(space==1){
					z.setY(y);
					World[x][y]='Z';
				}
				
				else if(space==2)
					fight(z,x,y,x,(y-1));
		}
	}
		else if(direction == 2){
			if(x!=0){
				x-=1;
				int space = z.move(World[x][y]);
				
				if(space==1){
					z.setX(x);
					World[x][y]='Z';
				}
				
				else if(space==2)
					fight(z,x,y,(x+1),y);
		}
	}
		else{
			if(y!=0){
				y-=1;
				int space = z.move(World[x][y]);
				
				if(space==1){
					z.setY(y);
					World[x][y]='Z';
				}
				
				else if(space==2)
					fight(z,x,y,x,(y+1));
		}
	}
}

/*fight
 * Takes in a zombie and four integers
 * It locates the human in its array
 * Once found it runs the fight function created above
 */ 
void world::fight(zombie &z, int hx, int hy, int zx, int zy){
	human temp;
	int hPos=-1;
	for(int i=0; i<8; i++){
		if(Humans[i].getX()==hx&&Humans[i].getY()==hy){
			temp = Humans[i];
			hPos = i;
		}
	}
	if(hPos==-1){
		cout << "welp" << endl;
		exit(1);
	}
	else{
		fight(temp, zx, zy);
	}
}
/*print function
 * Takes in no parameters
 * Prints the contents of the World grid
 * Returns nothing
 */
void world::print(){
	cout << "+---+---+---+---+---+---+---+---+" << endl;
	for(int i=0; i<8; i++){
		for(int j=0; j<8; j++){
			cout << "| " << World[i][j] << " ";
		}
		cout << "|" <<endl;
		cout << "+---+---+---+---+---+---+---+---+" << endl;
	}
	cout << endl;
}
/*setUp function
 * Takes in no parameters
 * Sets up where the characters for h and z will be on the grid
 * Also sets the attack for each human and zombie
 * Returns nothing
 */
void world::setUp(){
	for(int i=0; i<8; i++){
		for(int j=0; j<8; j++){
		World[i][j] = ' ';
		}
	}
	for(int i=0; i<8; i++){
		Humans[i].setX(-1);
		Humans[i].setY(-1);
		Humans[i].setAttack((rand()%100)+1);
	}
	for(int i=0; i<8; i++){
		int x = rand()%8;
		int y = rand()%8;
		if(!anyHumansHere(x,y)){
			Humans[numHumans].setX(x);
			Humans[numHumans].setY(y);
			numHumans++;
		}
		else
			--i;
	}
	for(int i=0; i<9; i++){
		Zombies[i].setX(-1);
		Zombies[i].setY(-1);
		Zombies[i].setAttack((rand()%50)+50);
	}
	for(int i=0; i<1; i++){
		int x = rand()%8;
		int y = rand()%8;
		if(!anyHumansHere(x,y)){
			Zombies[0].setX(x);
			Zombies[0].setY(y);
			numZombies++;
		}
		else{
			--i;
		}
	}
}
/*boolean type anyHumansHere function
 * take in grid integers for x and y
 * this function checks to see if a human occupies a spot on the grid
 */
bool world::anyHumansHere(int x, int y){
	for(int i=0; i<8; i++){
		if(Humans[i].getX()==x && Humans[i].getY()==y)
		return true;
	}
return false;
}
/*boolean type anyZombiessHere function
 * take in grid integers for x and y
 * this function checks to see if a zombie occupies a spot on the grid
 */
bool world::anyZombiesHere(int x, int y){
	for(int i=0; i<9; i++){
		if(Zombies[i].getX()==x && Zombies[i].getY()==y)
		return true;
	}
return false;
}
/*refresgWorld function
 * Iterates through the world and checks if any humans or zombies have that x y coordinate
 * If so it places a H or Z in that spot repectivly
 */
void world::refreshWorld(){
	for(int i=0; i<8; i++){
		for(int j=0; j<8; j++){
			if(anyHumansHere(i,j))
				World[i][j]='H';
			else if(anyZombiesHere(i,j))
				World[i][j] = 'Z';
			else
				World[i][j] = ' ';
		}
	}
}
