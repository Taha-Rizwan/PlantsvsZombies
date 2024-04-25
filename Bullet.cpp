#include "Bullet.h"
Bullet::Bullet(int x, int y, float bulletSpeed, string spritePath, int textureX, int textureY): pos(x,y),bulletSpeed(bulletSpeed) {
	bulletTexture.loadFromFile(spritePath);
	bulletSprite.setTexture(bulletTexture);
	bulletSprite.setTextureRect(IntRect(0,0,textureX,textureY));
	exists = true;
}


bool Bullet::getExists() {
	return exists;
}

void Bullet::move() {
		pos.move(bulletSpeed);
		if (pos.getPos()[0] > 1075) {
			exists = false;
		}
}

void Bullet::draw(RenderWindow& window){
	if (exists) {
		bulletSprite.setPosition(pos.getPos()[0], pos.getPos()[1]);
		window.draw(bulletSprite);
	}
}
void Bullet::toggleExists() {
	exists = !exists;
}