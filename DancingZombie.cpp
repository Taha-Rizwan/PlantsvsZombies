#include"DancingZombie.h"

DancingZombie::DancingZombie(int x, int y, int waitTime) : Zombie(x, y, 200, "./SFML/images/dancingZombie2.png", "DancingZombie", 59.4,77.2, 15,0, waitTime, false, 20,10) {
	sprite.setScale(2, 2);
	startY = 3;
}

void DancingZombie::move() {
	if (!getWait()) {
		float time = moveClock.restart().asSeconds();
		Entity::pos.set(-speed * time);
	}
}