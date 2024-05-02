#include"SimpleZombie.h"

SimpleZombie::SimpleZombie(int x, int y) : Zombie(x, y, 30, "./SFML/images/zombie.png", "SimpleZombie", 46, 50, 10, 2, 0, false, 20, 7) {}


void SimpleZombie::move() {
	float time = moveClock.restart().asSeconds();
	pos.set(-speed * time * 2);
}

