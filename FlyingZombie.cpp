#include"FlyingZombie.h"

FlyingZombie::FlyingZombie(int x, int y) : Zombie(x, y,200, "./SFML/images/flyingZombie.png", "FlyingZombie",34.2, 58,20,0.01, 0,false,0,20) {

}

void FlyingZombie::move() {
	float time;	
	time = Entity::clock.restart().asSeconds();
	Entity::pos.set(-speed*time);

}