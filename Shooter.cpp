#include "Shooter.h"

Shooter::Shooter(int x, int y, double reloadTime, int bulletSpeed, std::string bulletSpritePath, double textureX, double textureY) :pos(x, y), reloadTime(reloadTime), bulletSpeed(bulletSpeed), bulletSpritePath(bulletSpritePath),textureX(textureX),textureY(textureY),canShot(true) {
	bullet = nullptr;
}

Bullet* Shooter::shoot() {
	bullet = nullptr;
	if (canShot) {

		if (sClock.getElapsedTime().asSeconds() >= reloadTime) {
			sClock.restart();
			bullet = new Bullet(pos.pos[0], pos.pos[1], bulletSpeed, bulletSpritePath, textureX, textureY);

		}

	}
	return bullet;
}