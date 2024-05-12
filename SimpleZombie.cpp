#include"SimpleZombie.h"

SimpleZombie::SimpleZombie(int x, int y,int wait) : Zombie(x, y, 15, "./SFML/images/zombie.png", "SimpleZombie", 46, 50, 10, 1, wait, false, 20, 7) {}


void SimpleZombie::move() {
	if (!eat&& !getWait()) {
		float time = moveClock.restart().asSeconds();
		
			pos.set(-speed * time * 2);
	}
}

void SimpleZombie::eatPlant(Plant* plant) {
	Zombie::eatPlant(plant);
	if (eat == true && exists) {
		startY = 3;
	}
}

