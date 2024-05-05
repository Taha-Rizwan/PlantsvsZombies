#include "CherryBomb.h"

CherryBomb::CherryBomb(int x, int y) : Plant(x, y, 49, "./SFML/images/CherryBomb.png", "Cherry Bomb", 112, 81, 5, 175, 1, "./SFML/images/cherrybombCard.png") {
	sprite.setScale(0.5, 0.5);
	sprite.setColor(sf::Color(255, 255, 255, 128));
	explodeTime = 4;
}


void CherryBomb::draw(sf::RenderWindow& window, int y) {
	if (exists) {
		sprite.setPosition(pos.pos[0], pos.pos[1]);
		if (clock.getElapsedTime().asSeconds() < explodeTime / 6.0) {
			sprite.setScale(0.75, 0.75);
			sprite.setColor(sf::Color(255, 255, 255, 192));

		}
		else if (clock.getElapsedTime().asSeconds() < explodeTime / 4.0) {
			sprite.setScale(0.9, 0.9);
			sprite.setColor(sf::Color(255, 255, 255, 255));
		}
		else if (clock.getElapsedTime().asSeconds() < explodeTime / 2.0) {
			sprite.setScale(1.1, 1.1);
			sprite.setColor(sf::Color(255, 0, 0, 255));
		}
		else if(clock.getElapsedTime().asSeconds() < explodeTime / 1.5){
			texture.loadFromFile("./SFML/images/Boom.png");
			sprite.setTexture(texture);
			sprite.setTextureRect(sf::IntRect(0, 0, 213, 160));
			sprite.setColor(sf::Color(255, 255, 255, 255));
			sprite.setScale(1, 1);
			
		}
		else {
			exists = false;
		}
		window.draw(sprite);
	}
}

Position CherryBomb::getPos() {
	return pos;
}
