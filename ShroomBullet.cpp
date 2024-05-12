#include "ShroomBullet.h"

ShroomBullet::ShroomBullet(int x, int y, int range): Bullet(x, y, 5, "./SFML/images/fumeBullets.png", 167, 51),x(0),range(range*10) {
	setType("fume");
	bulletSprite.setScale(0.7, 0.7);
}

void ShroomBullet::move(bool state) {
	if (!state) {
		pos.set(bulletSpeed);
		if (pos.pos[0] > 1075 || clock.getElapsedTime().asSeconds() > 3) {
			exists = false;
		}
	}
}

void ShroomBullet::draw(sf::RenderWindow& window,bool state) {
	
	static sf::Clock animateClock;

	if (exists) {
		
		if (animateClock.getElapsedTime().asSeconds() >= 0.3)
		{
			animateClock.restart();
			x++;
			bulletSprite.setTextureRect(sf::IntRect( x * 167, 0, textureX, textureY));
		}

		if (x >= 9)
			x = 0;
		
		bulletSprite.setPosition(pos.pos[0], pos.pos[1]);
		window.draw(bulletSprite);
		this->move(state);
	}
}
