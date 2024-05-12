#include"DancingZombie.h"

DancingZombie::DancingZombie(int x, int y, int waitTime) : Zombie(x, y, 20, "./SFML/images/dancingZombieGif.png", "DancingZombie", 250,415, 30,0, waitTime, false, 20,8) {
	sprite.setScale(0.3, 0.3);
	startY = 0;

}

void DancingZombie::move() {
	if (!getWait() && exists) {
		float time = moveClock.restart().asSeconds();
		Entity::pos.set(-speed * time);
	
	}
}

