#include "world.h"
#include<stdlib.h>
#include<iostream>
using namespace std;
world::world(){
	numHumans = 0;
	numZombies = 0;
}
void world::move(human &h){
		if(!h.dead){
		int direction = rand()&4-1;
		int x = h.getX();
		int y = h.getY();
		if(direction == 0){
			if(x!=7){
				x+=1;
				if(World[x][y]=='Z'){
					h.setX(-1);
					h.setY(-1);
					zombie *a = new zombie(x,y,true);
					Zombies[numZombies] = *a;
					World[x][y] = 'Z';
				}
				else if(h.move(World[x][y])){
					h.setX(x);
					World[x][y]='H';
			}
		}
	}
		else if(direction == 1){
			if(y!=7){
			y+=1;
			if(World[x][y]=='Z'){
					h.setX(-1);
					h.setY(-1);
					zombie *a = new zombie(x,y,true);
					Zombies[numZombies] = *a;
					World[x][y] = 'Z';
				}
				else if(h.move(World[x][y]))
					h.setY(y);
					World[x][y]='H';
			}
		}
		else if(direction == 2){
			if(x!=0){
				x-=1;
				if(World[x][y]=='Z'){
					h.setX(-1);
					h.setY(-1);
					zombie *a = new zombie(x,y,true);
					Zombies[numZombies] = *a;
					World[x][y] = 'Z';
				}
				else if(h.move(World[x][y]))
					h.setX(x);
					World[x][y]='H';
			}
		}
		else{
			if(y!=0){
				y-=1;
				if(World[x][y]=='Z'){
					h.setX(-1);
					h.setY(-1);
					zombie *a = new zombie(x,y,true);
					Zombies[numZombies] = *a;
					World[x][y] = 'Z';
				}
				else if(h.move(World[x][y]))
					h.setY(y);
					World[x][y]='H';
			}
		}
		
	}
}
void world::move(zombie &z){
	if(!z.dead){
		int direction = rand()&4;
		int x = z.getX();
		int y = z.getY();
		if(direction == 0){
			if(x!=7){
				char *a = World[++x,y];
				if(z.move(*a))
					z.setX(++x);
			}
		}
		else if(direction == 1){
			if(y!=7){
				char *a = World[x,++y];
				if(z.move(*a))
					z.setY(++y);
			}
		}
		else if(direction == 2){
			if(x!=0){
				char *a = World[--x,y];
				if(z.move(*a))
					z.setX(--x);
			}
		}
		else{
			if(y!=0){
				char *a = World[x,--y];
				if(z.move(*a))
					z.setY(--y);
			}
		}
		
	}
	
}

void world::print(){
	for(int i=0; i<8; i++){
		for(int j=0; j<8; j++){
			cout << "|";
			switch(World[i][j]){
				case 'H':
					cout << "H";
					break;
				case 'Z':
					cout << "Z";
					break;
				case ' ':
					cout << " ";
					break;
				default:
					cout << "Uhh thats not good..." << endl;
					break;			
			}
		}
		cout << "|" <<endl;
	}
	cout << endl;
}

void world::setUp(){
	for(int i=0; i<8; i++){
		for(int j=0; j<8; j++){
		World[i][j] = ' ';
		}
	}
	
	for(int i=0; i<8; i++){
		int x = rand()%8;
		int y = rand()%8;
		if(!anyHumansHere(x,y)){
			human *a = new human(x,y,false);
			++numHumans;
			Humans[numHumans] = *a;
		}
		else
			--i;
	}
	for(int i=0; i<9; i++){
		Zombies[i].setX(-1);
		Zombies[i].setY(-1);
	}
	for(int i=0; i<1; i++){
		int x = rand()%8;
		int y = rand()%8;
		if(!anyHumansHere(x,y)){
			zombie *a = new zombie(x,y,true);
			++numZombies;
			Zombies[0] = *a;
			Zombies[1].setX(-1);
			Zombies[1].setY(-1);
		}
		else{
			--i;
		}
	}
}
bool world::anyHumansHere(int x, int y){
	for(int i=0; i<8; i++){
		if(Humans[i].getX()==x && Humans[i].getY()==y)
		return true;
	}
return false;
}
bool world::anyZombiesHere(int x, int y){
	for(int i=0; i<9; i++){
		if(Zombies[i].getX()==x && Zombies[i].getY()==y)
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
	}
}
