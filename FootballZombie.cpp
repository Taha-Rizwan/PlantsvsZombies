#include"FootballZombie.h"
#include<iostream>
using namespace std;

FootballZombie::FootballZombie(int x,int y,int waitTime): Zombie(x,y,30,"./SFML/Images/footballZombie.png","FootballZombie",104,80,20,0,waitTime,false,20,5),plantAhead(false){
	sprite.setScale(1.5,1.5);
	startY = 0;
}


void FootballZombie::move() {
	if (!eat && !getWait()) {
		static int x = 0;
		static float elapsedTime = 0.0f; 

		float time = moveClock.restart().asSeconds();
		elapsedTime += time; 

		if (elapsedTime >= 1.1f) {
			if (x == 0 || x == 3) {
				pos.set(-speed, 0);

			}
			else if ((x == 1 || x == 5)) {
				if (pos.pos[1]-(speed*1.5) <= 10) {
					//cout << "Football zombie stopped from upper boundary\n";
					pos.set(0,speed * 1.5);
				}
				else{
					pos.set(0, -speed * 1.5);
				}
			}
			else if (x == 2 || x == 4) {
				if (pos.pos[1]+(speed*1.5) >= 500) {
					//cout << "Football zombie stopped from lower boundary\n";
					pos.set(0, -speed * 1.5);
				}
				else {
					pos.set(0, speed * 1.5);
				}
			}
			x++;
			if (x > 5) {
				x = 0;
			}

			elapsedTime = 0.0f; 
		}
	}
}


void FootballZombie::eatPlant(Plant* plant) {
	if(exists)
		Zombie::eatPlant(plant);
	
}