#include"FootballZombie.h"
#include<iostream>
using namespace std;

FootballZombie::FootballZombie(int x,int y,int waitTime): Zombie(x,y,40,"./SFML/Images/footballZombie.png","FootballZombie",39.375,42.5,60,1,waitTime,false,20,8){
	sprite.setScale(2.5,2.5);
	startY = 1;
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
			else if (x == 1 || x == 5) {
				pos.set(0, -speed * 1.5);
			}
			else if (x == 2 || x == 4) {
				pos.set(0, speed * 1.5);
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
	Zombie::eatPlant(plant);
	
}