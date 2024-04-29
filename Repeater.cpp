#include "Repeater.h"

Repeater::Repeater(int x, int y) : Plant(x, y, 100, "./SFML/images/Repeater.png", "Repeater", 27.5, 34, 10, 50, 7), Shooter(x + 40, y + 10, 2.9, 5, "./SFML/images/peashooterBullet.png", 10, 15) {
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
		bullet = new Bullet(Shooter::pos.pos[0],Shooter::pos.pos[1], bulletSpeed, bulletSpritePath, textureX, textureY);
		return bullet;
	}

	return bullet;
}