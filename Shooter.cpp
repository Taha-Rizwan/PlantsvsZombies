#include "Shooter.h"

Shooter::Shooter(Position * pos,
	double reloadTime, int bulletSpeed, std::string bulletSpritePath, double textureX, double textureY) :pos(pos), reloadTime(reloadTime), bulletSpeed(bulletSpeed), bulletSpritePath(bulletSpritePath),textureX(textureX),textureY(textureY),canShot(true) {
	bullet = nullptr;
	shootSoundBuffer.loadFromFile("./SFML/Music/shoot.mp3");
	shootSound.setBuffer(shootSoundBuffer);
}

Bullet* Shooter::shoot() {
	bullet = nullptr;
	if (canShot) {

		if (sClock.getElapsedTime().asSeconds() >= reloadTime) {
			shootSound.play();
			sClock.restart();
			bullet = new Bullet(pos->pos[0]+40, pos->pos[1]+10, bulletSpeed, bulletSpritePath, textureX, textureY);

		}

	}
	return bullet;
}