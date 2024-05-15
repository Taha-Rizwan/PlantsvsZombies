#include"DancingZombie.h"

DancingZombie::DancingZombie(int x, int y, int waitTime) : Zombie(x, y, 20, "./SFML/images/dancingZombieGif.png", "DancingZombie", 250,415, 30,0, waitTime, false, 20,8) {
	sprite.setScale(0.3, 0.3);
	startY = 0;

}

void DancingZombie::move(bool state) {
	if (!getWait()&&!state) {
		//float time = moveClock.restart().asSeconds();
		if (!plantAhead) {
			Entity::pos.set(-speed * 0.10);
		}
		else {
			if (pos.pos[1] + (speed * 0.05) >= 500) {
				Entity::pos.set(-speed * 0.05, -speed * 0.05);
			}
			else if (pos.pos[1] - (speed * 0.05) <= 50) {
				Entity::pos.set(-speed * 0.05, speed * 0.05);
			}
			else {
				Entity::pos.set(-speed * 0.05, speed * 0.05);
			}
				plantAhead = false;
		}
	}
}

