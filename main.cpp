#include "world.cpp"
int main(int argc, char **argv){
world god = new world();
bool allDead = false;
int day = 0;
while(!allDead){
	cout << "Day: " << day << endl;
		
	allDead=true;
	for(int i=0; i<8; i++){
		if(god.Humans[i].dead==false)
			allDead = true;
		}
		++day;
	}
}
