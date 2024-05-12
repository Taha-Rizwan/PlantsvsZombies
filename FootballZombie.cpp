#include"FootballZombie.h"
#include<iostream>
using namespace std;

FootballZombie::FootballZombie(int x,int y,int waitTime): Zombie(x,y,30,"./SFML/Images/footballZombie.png","FootballZombie",104,80,20,0,waitTime,false,20,5){
	sprite.setScale(1.5,1.5);
	startY = 0;
}


void FootballZombie::move(bool state) {
	if (!eat && !getWait() && !state) {

		float time = moveClock.restart().asSeconds();
		if (!plantAhead) {
			pos.set(-speed * time);
		}
		else {
			if (pos.pos[1] + (speed * time) >= 500) {
				pos.set(0, -speed * time);
			}
			else if (pos.pos[1] - (speed * time) <= 10) {
				pos.set(0, speed * time);
			}
			else {
				pos.set(0, speed * time);
			}
			plantAhead = false;
		}
	}
}


void FootballZombie::eatPlant(Plant* plant) {
	if(exists)
		Zombie::eatPlant(plant);
	
}