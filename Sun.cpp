#include"Sun.h"
#include<iostream>
using namespace std;

Sun::Sun(int x, int y) :pos(x,y), sunProduced(50), collected(false),textureX(71),textureY(71),sprites(22) {
	sunTexture.loadFromFile("./SFML/Images/sun.png");
	sunSprite.setTexture(sunTexture);
	sunSprite.setTextureRect(IntRect(0, 0, textureX, textureY));
	sunSprite.setPosition(pos.pos[0], pos.pos[1]);
}

void Sun::draw(RenderWindow& window) {
	static int x = 0;
	sunSprite.setPosition(pos.pos[0], pos.pos[1]);
	if (sClock.getElapsedTime().asSeconds() > 0.2f) {
		sunSprite.setTextureRect(IntRect(x * textureX, 0, textureX, textureY));
		if (x >= sprites - 1) {
			x = -1;
		}
		x++;
		sClock.restart();
	}
	window.draw(sunSprite);
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



bool Sun::isClicked(Vector2f& mousePos) {
	return sunSprite.getGlobalBounds().contains(mousePos);
}

void Sun::collectSun(Event& event) {
	Vector2f mousePos(event.mouseButton.x, event.mouseButton.y);
	if (event.type == Event::MouseButtonPressed) {
		if (isClicked(mousePos)) {
			collected = true;
			cout << "Collected\n";
			sunSprite.setColor(Color(255, 255, 255, 128));
		}
	}
}