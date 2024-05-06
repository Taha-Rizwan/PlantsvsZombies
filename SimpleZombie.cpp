#include"SimpleZombie.h"

SimpleZombie::SimpleZombie(int x, int y) : Zombie(x, y, 30, "./SFML/images/zombie.png", "SimpleZombie", 46, 50, 10, 1, 0, false, 20, 7) {}


void SimpleZombie::move() {
	if (!eat) {
		float time = moveClock.restart().asSeconds();
		pos.set(-speed * time * 2);
	}
}

void SimpleZombie::eatPlant(Plant* plant) {
	Zombie::eatPlant(plant);
	if (eat == true) {
		startY = 3;
	}
}

