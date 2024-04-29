#include "Shooter.h"

Shooter::Shooter(int x, int y, float reloadTime, int bulletSpeed, string bulletSpritePath, int textureX, int textureY) :pos(x, y), reloadTime(reloadTime), bulletSpeed(bulletSpeed), bulletSpritePath(bulletSpritePath),textureX(textureX),textureY(textureY) {
	bullet = nullptr;
}

Bullet* Shooter::shoot() {
	bullet = nullptr;

	if (clock.getElapsedTime().asSeconds() >= reloadTime) {
		clock.restart();
		bullet = new Bullet(pos.pos[0], pos.pos[1], bulletSpeed, bulletSpritePath, textureX, textureY);
		
	}

	return bullet;
}