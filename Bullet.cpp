#include "Bullet.h"
Bullet::Bullet(int x, int y, float bulletSpeed, string spritePath, int textureX, int textureY): pos(x,y),bulletSpeed(bulletSpeed) {
	bulletTexture.loadFromFile(spritePath);
	bulletSprite.setTexture(bulletTexture);
	bulletSprite.setTextureRect(IntRect(0,0,textureX,textureY));
	bulletSprite.setScale(1.5, 1.5);
	exists = true;
}


bool Bullet::getExists() {
	return exists;
}

void Bullet::move() {
		pos.set(bulletSpeed);
		if (pos.pos[0] > 1075) {
			exists = false;
		}

}

void Bullet::draw(RenderWindow& window){
	if (exists) {
		bulletSprite.setPosition(pos.pos[0], pos.pos[1]);
		window.draw(bulletSprite);
		this->move();
	}
}
void Bullet::toggleExists() {
	exists = !exists;
}