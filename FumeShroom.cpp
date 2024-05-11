#include "FumeShroom.h"
#include "ShroomBullet.h"
FumeShroom::FumeShroom(int x, int y) : Plant((x-100), (y), 100, "./SFML/images/fumeshroom.png", "SnowPea", 118, 52, 10, 75, 4, "./SFML/images/fumeshroomCard.png"), Shooter(&(Plant::pos), 3, 20, "./SFML/images/fumeBullets.png", 15, 10) {
	sprite.setScale(1.5, 1.5);
}
Bullet* FumeShroom::shoot() {
	Bullet* bullet = nullptr;

	if (Shooter::sClock.getElapsedTime().asSeconds() >= reloadTime) {
		Shooter::sClock.restart();
		bullet = new ShroomBullet(Shooter::pos->pos[0], Shooter::pos->pos[1], 3);

	}

	return bullet;
}