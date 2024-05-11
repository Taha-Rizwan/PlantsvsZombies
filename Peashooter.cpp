#include "Peashooter.h"

Peashooter::Peashooter(int x, int y) : Plant(x,y, 100, "./SFML/images/c/peashooter.png", "Peashooter", 71, 71, 8, 100, 13,"./SFML/images/peashooterCard.png"), Shooter(&(Plant::pos), 3, 20, "./SFML/images/peashooterBullet.png", 10, 15) {}

Bullet* Peashooter::shoot() {
	Bullet* ptr = nullptr;
	if (exists) {
		ptr = Shooter::shoot();
	}
	return ptr;
}