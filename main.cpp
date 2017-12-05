#include "world.cpp"
int main(int argc, char **argv){
world god;
bool allDead = false;
int day = 1;
god.setUp();
//while(!allDead){
cout << "Day: " << day << endl;
god.refreshWorld();
god.print();

for(int i=0; i<8; i++){
god.move(god.Humans[i]);
}

allDead=true;
for(int i=0; i<8; i++){
	if(god.Humans[i].dead==false)
		allDead = true;
}
	++day;
//	}
}
