#include"FlyingZombie.h"

FlyingZombie::FlyingZombie(int x, int y,int waitTime) : Zombie(x, y, 200, "./SFML/Images/flyingZombieGif.png", "FlyingZombie", 88, 140, 20, 0, waitTime, false, 0, 11) {
	sprite.setScale(1,1);
}

void FlyingZombie::move(bool state) {
	if (!getWait()&&!state) {
		float time;
		time = moveClock.restart().asSeconds();
		Entity::pos.set(-speed * time * 2);
	}
}
