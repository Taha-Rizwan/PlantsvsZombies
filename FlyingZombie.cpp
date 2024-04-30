#include"FlyingZombie.h"

FlyingZombie::FlyingZombie(int x, int y) : Zombie(x, y,200, "./SFML/images/flyingZombie.png", "FlyingZombie",30, 60,20,0.01, 0,false,0,7) {

}

void FlyingZombie::move() {
	float time;	
	time = Entity::clock.restart().asSeconds();
	Entity::pos.set(-speed*time);

}