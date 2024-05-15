#include"FootballZombie.h"
#include<iostream>
using namespace std;

FootballZombie::FootballZombie(int x,int y,int waitTime): Zombie(x,y,30,"./SFML/Images/footballZombie.png","FootballZombie",104,80,20,0,waitTime,false,20,5){
	sprite.setScale(1.5,1.5);
	startY = 0;
}


void FootballZombie::move(bool state) {
	if (!eat && !getWait() && !state) {

		//float time = moveClock.restart().asSeconds();
		if (!plantAhead) {
			pos.set(-speed * 0.10);
		}
		else {
			if (pos.pos[1] + (speed * 0.05) >= 470) {
				pos.set(0, -speed * 0.05);
			}
			else if (pos.pos[1] - (speed * 0.05) <= 30) {
				pos.set(0, speed * 0.05);
			}
			else {
				pos.set(0, speed * 0.05);
			}
			plantAhead = false;
		}
	}
}
