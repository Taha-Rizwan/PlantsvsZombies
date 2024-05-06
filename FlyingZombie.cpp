#include"FlyingZombie.h"

FlyingZombie::FlyingZombie(int x, int y) : Zombie(x, y, 200, "./SFML/Images/flyingZombie.png", "FlyingZombie", 34.95, 59, 20, 0, 0, false, 0, 3) {
	sprite.setScale(2, 2);
}

void FlyingZombie::move() {
	
	float time;	
	time = moveClock.restart().asSeconds();
	Entity::pos.set(-speed*time*2);

}
