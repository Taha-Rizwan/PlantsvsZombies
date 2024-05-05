#include "Repeater.h"

Repeater::Repeater(int x, int y) : Plant(x, y, 100, "./SFML/images/c/repeater.png", "Repeater", 71, 71, 10, 200, 13,"./SFML/images/repeaterCard.png"), Shooter(&(Plant::pos),2.9, 20, "./SFML/images/peashooterBullet.png", 10, 15) {
	shot = false;
}
//Function to burst shoot
Bullet* Repeater::shoot() {
	Bullet* bullet = nullptr;
	bullet = Shooter::shoot();
	if (bullet != nullptr) {
		shot = true;
		clock.restart();
		return bullet;
	}
	if (shot && clock.getElapsedTime().asMilliseconds()>175) {
		clock.restart();
		shot = false;
		bullet = new Bullet(Shooter::pos->pos[0] + 40,Shooter::pos->pos[1]+10, bulletSpeed, bulletSpritePath, Shooter::textureX, Shooter::textureY);
		return bullet;
	}

	return bullet;
}