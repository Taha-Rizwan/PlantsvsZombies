#include"DolphinRiderZombie.h"

DolphinRiderZombie::DolphinRiderZombie(int x, int y) : Zombie(x, y, 200, "./SFML/images/dolphinRider", "DolphinRider", 27.5, 34, 2, 20, 0, false, 20, 7) {

}

void DolphinRiderZombie::move() {
	////Collission Logic


	float time;
	time = Entity::clock.restart().asSeconds();
	Entity::pos.set(-speed * time);
}