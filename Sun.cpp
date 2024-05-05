#include"Sun.h"

Sun::Sun(int x, int y) :pos(x,y), sunProduced(50), collected(false),textureX(71),textureY(71),sprites(22) {
	sunTexture.loadFromFile("./SFML/Images/sun.png");
	sunSprite.setTexture(sunTexture);
	sunSprite.setTextureRect(sf::IntRect(0, 0, textureX, textureY));
	sunSprite.setPosition(pos.pos[0], pos.pos[1]);
}

void Sun::draw(sf::RenderWindow& window) {
	static int x = 0;
	if (!collected) {
		sunSprite.setPosition(pos.pos[0], pos.pos[1]);
		if (sClock.getElapsedTime().asSeconds() > 0.2f) {
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
		if (pos.pos[1] <= 50) {
			pos.set(0, 10);
		}
	}
	else if(collected==true) {
		pos.set(-10, -10);	
	}
}



bool Sun::isClicked(sf::Vector2f& mousePos) {
	return sunSprite.getGlobalBounds().contains(mousePos);
}

void Sun::collectSun(sf::Event& event) {
	sf::Vector2f mousePos(event.mouseButton.x, event.mouseButton.y);
	if (event.type == sf::Event::MouseButtonPressed) {
		if (isClicked(mousePos)) {
			collected = true;
			sunSprite.setColor(sf::Color(255, 255, 255, 128));
		}
	}
}