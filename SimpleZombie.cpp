#include"SimpleZombie.h"
#include<iostream>
SimpleZombie::SimpleZombie(int x, int y,int wait) : Zombie(x, y, 15, "./SFML/images/zombie.png", "SimpleZombie", 46, 50, 10, 1, wait, false, 20, 7) {}


void SimpleZombie::move(bool state) {
	if (!eat&& !getWait() && !state) {
		//float time = moveClock.restart().asSeconds();
		pos.set(-speed*0.1);
	}
}

void SimpleZombie::eatPlant(Plant* plant) {
	if (exists && plant->getExists()) {
		eat = true;
		//startY = 3;
		plant->hit(damage);
		if (!(plant->getExists())) {
			eat = false;
			startY = 0;
		}
	}
	if (eat == true && exists && plant->getExists()) {
		startY = 3;
	}
}

