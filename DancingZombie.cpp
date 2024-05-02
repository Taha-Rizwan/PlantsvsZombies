#include"DancingZombie.h"

DancingZombie::DancingZombie(int x, int y) : Zombie(x, y, 200, "./SFML/images/dancingZombie.png", "DancingZombie", 24, 36, 6, 20, 0, false, 20,4 ) {

}

void DancingZombie::move() {
	//Collision Logic/........
	
	
	float time = moveClock.restart().asSeconds();
	Entity::pos.set(-speed * time);
}