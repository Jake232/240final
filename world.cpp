#include "world.h"
#include<stdlib.h>
#include<iostream>
using namespace std;
void world::move(human h){
		if(!h.dead){
		int direction = rand()&4;
		int x = Human.getX();
		int y = Human.getY();
		if(direction == 0){
			if(x!=7){
				if(h.move(World[++x,y]))
					h.setX(++x);
			}
		}
		else if(direction == 1){
			if(y!=7){
				if(h.move(World[x,++y]))
					h.setY(++y);
			}
		}
		else if(direction == 2){
			if(x!=0){
				if(h.move(World[--x,y]))
					h.setX(--x);
			}
		}
		else{
			if(y!=0){
				if(h.move(World[x,--y]))
					h.setY(--y);
			}
		}
		
	}
}
void world::move(zombie z){
	if(!z.dead){
		int direction = rand()&4;
		int x = Human.getX();
		int y = Human.getY();
		if(direction == 0){
			if(x!=7){
				if(z.move(World[++x,y]))
					z.setX(++x);
			}
		}
		else if(direction == 1){
			if(y!=7){
				if(z.move(World[x,++y]))
					z.setY(++y);
			}
		}
		else if(direction == 2){
			if(x!=0){
				if(z.move(World[--x,y]))
					z.setX(--x);
			}
		}
		else{
			if(y!=0){
				if(z.move(World[x,--y]))
					z.setY(--y);
			}
		}
		
	}
	
}

void world::print(){
	for(int i=0; i<8; i++){
		for(int j=0; j<8; j++){
			switch(world[i][j]){
				case 'H':
					cout << "| H ";
					break;
				case 'Z':
					cout << "| Z ";
					break;
				case ' ':
					cout << "|  "
					break;
				default:
					cout << "Uhh thats not good..." << endl;
					break;			
			}
			cout << "|" << endl;
		}
	}
}

void world::setUp(){
	for(int i=0; i<8; i++){
		for(int j=0; j<8; j++)
		World[i][j] = ' ';
	}
	for(int i=0; i<8; i++){
		int x = rand()%8;
		int y = rand()%8;
		if(!anyHumansHere(x,y)){
			human a = new human(x,y,false);
			++numHumans;
			Human[numHumans] = a;
		}
		else
			--i;
}
bool world::anyHumansHere(int x, int y){
	for(int i=0; i<8; i++){
		if(Human[i].getX==x&&Human[i].getY==y)
		return true;
	}
return false;
}
bool world::anyZombiesHere(int x, int y){
	for(int i=0; i<9; i++){
		if(Zombie[i].getX==x && Zombie[i].getY==y)
		return true;
	}
return false;
}
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
