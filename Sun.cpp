#include"Sun.h"

Sun::Sun(int x, int y) :pos(x,y), sunProduced(50), collected(false),textureX(71),textureY(71),sprites(22) {
	sunTexture.loadFromFile("./SFML/Images/sun.png");
	sunSprite.setTexture(sunTexture);
	sunSprite.setTextureRect(sf::IntRect(0, 0, textureX, textureY));
	sunSprite.setPosition(pos.pos[0], pos.pos[1]);
}

void Sun::draw(sf::RenderWindow& window) {
	if (collected == false) {
		static int x = 0;
		sunSprite.setPosition(pos.pos[0], pos.pos[1]);
		if (sClock.getElapsedTime().asSeconds() > 0.2f) {
			sunSprite.setTextureRect(sf::IntRect(x * textureX, 0, textureX, textureY));
			sunSprite.setTextureRect(sf::IntRect(x * textureX, 0, textureX, textureY));
			if (x >= sprites - 1) {
				x = -1;
			}
			x++;
			sClock.restart();
		}
		window.draw(sunSprite);
	}
}


void Sun::move() {
	if (collected == false) {
		if (pos.pos[1] <= 100) {
			pos.set(0, 5);
		}
	}
	else if(collected==true) {
		
		pos.pos[0]= 200 + ((rand() % 9) * 80);
		pos.pos[1] = -10;
	}
}

bool Sun::collectSun(sf::Event& event, sf::RenderWindow& window) {
	sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
	if (event.type == sf::Event::MouseButtonPressed && !collected) {
		if (isClicked(mousePos)) {
			collected = true;
			sClock.restart();
			return true;
		}
	}
	return false;
}

bool Sun::isClicked(sf::Vector2f& mousePos) {
	return sunSprite.getGlobalBounds().contains(mousePos);
}

void Sun::appear() {
	if (collected) {
		sf::Time elapsed = sClock.getElapsedTime();
		if (elapsed.asSeconds() >= 5.0f) {
			collected = false;
		}
	}
}

bool Sun::isCollected()const {
	return collected;
}

int Sun::getSunProduced()const {
	return sunProduced;
}

sf::Sprite Sun::getSprite()const {
	return sunSprite; 
}