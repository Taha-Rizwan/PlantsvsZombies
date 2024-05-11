#include "Bullet.h"
Bullet::Bullet(int x, int y, float bulletSpeed, std::string spritePath, double textureX, double textureY): pos(x,y),bulletSpeed(bulletSpeed),textureX(textureX),textureY(textureY) {
	bulletTexture.loadFromFile(spritePath);
	bulletSprite.setTexture(bulletTexture);
	bulletSprite.setTextureRect(sf::IntRect(0,0,textureX,textureY));
	bulletSprite.setScale(1.5, 1.5);
	exists = true;
	type = "normal";
}


bool Bullet::getExists() {
	return exists;
}

void Bullet::move() {
		pos.set(bulletSpeed);
		if (pos.pos[0] > 945) {
			exists = false;
		}

}

void Bullet::draw(sf::RenderWindow& window){
	if (exists) {
		bulletSprite.setPosition(pos.pos[0], pos.pos[1]);
		window.draw(bulletSprite);
		this->move();
	}
}
void Bullet::toggleExists() {
	exists = !exists;
}
void Bullet::setType(std::string t) {
	type = t;
}
std::string Bullet::getType() {
	return type;
}
sf::Sprite* Bullet::getSprite() {
	return &bulletSprite;
}