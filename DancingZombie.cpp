#include"DancingZombie.h"

DancingZombie::DancingZombie(int x, int y, int waitTime) : Zombie(x, y, 20, "./SFML/images/dancingZombieGif.png", "DancingZombie", 250,415, 30,0, waitTime, false, 20,8) {
	sprite.setScale(0.3, 0.3);
	startY = 0;

}

void DancingZombie::move(bool state) {
	if (!getWait()&&!state) {
		float time = moveClock.restart().asSeconds();
		if (!plantAhead) {
			Entity::pos.set(-speed * time);
		}
		else {
			if (pos.pos[1] + (speed * time) >= 500) {
				Entity::pos.set(-speed * time, -speed * time);
			}
			else if (pos.pos[1] - (speed * time) <= 50) {
				Entity::pos.set(-speed * time, speed * time);
			}
			else {
				Entity::pos.set(-speed * time, speed * time);
			}
				plantAhead = false;
		}
	}
}

