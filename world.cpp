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
				if(World[x][y]==' '){
					h.setX(x);
					World[x][y]='H';
				}
				else if(World[x][y]=='Z'){
					zombify(h);
			}
		}
	}
		else if(direction == 1){
			if(y!=7){
			y+=1;
			if(World[x][y]==' '){
					h.setY(y);
					World[x][y]='H';
			}
			else if(World[x][y]=='Z'){
					zombify(h);
				}
			}
		}
		else if(direction == 2){
			if(x!=0){
				x-=1;
				if(World[x][y]==' '){
					h.setX(x);
					World[x][y]='H';
				}
				else if(World[x][y]=='Z'){
					zombify(h);
				}
			}
		}
		else{
			if(y!=0){
				y-=1;
				if(h.move(World[x][y])){
					h.setY(y);
					World[x][y]='H';
				}
				else if(World[x][y]=='Z'){
					zombify(h);
				}
			}
		}
	}
}

void world::zombify(human &h){
	cout << "A human has turned into a zombie" << endl;
	
	int x = h.getX();
	int y = h.getY();
	
	Zombies[numZombies].x=x;
	Zombies[numZombies].y=y;
	numZombies++;
	
	World[x][y]='Z';
	
	h.setX(-1);
	h.setY(-1);
}

void world::move(zombie &z){
	int direction = rand()&4-1;
		int x = z.getX();
		int y = z.getY();
		if(direction == 0){
			if(x!=7){
				x+=1;
				if(World[x][y]==' '){
					z.setX(x);
					World[x][y]='Z';
				}
			}
		}
		else if(direction == 1){
			if(y!=7){
			y+=1;
			if(World[x][y]==' '){
					z.setY(y);
					World[x][y]='Z';
				}
			}
		}
		else if(direction == 2){
			if(x!=0){
				x-=1;
				if(World[x][y]==' '){
					z.setX(x);
					World[x][y]='Z';
				}
			}
		}
		else{
			if(y!=0){
				y-=1;
				if(World[x][y]==' '){
					z.setY(y);
					World[x][y]='Z';
				}
			}
		}
}

void world::print(){
	for(int i=0; i<8; i++){
		for(int j=0; j<8; j++){
			cout << "|" << World[i][j];
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
		Humans[i].setX(-1);
		Humans[i].setY(-1);
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
