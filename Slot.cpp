#include "Slot.h"

Slot::Slot(int x, int y):pos(x,y) {
	filled = false;
	rectangle.setSize(Vector2f(80, 100));
	rectangle.setFillColor(sf::Color(255, 255, 0, 128));
	rectangle.setPosition(x, y);
	rectangle.setOutlineColor(Color::Yellow);
	rectangle.setOutlineThickness(1);
}

void Slot::toggleFilled() {
	filled = !filled;
	normalState();
}

void Slot::normalState() {
	if (filled) {
		rectangle.setFillColor(sf::Color(255, 0, 0, 128));
		rectangle.setOutlineColor(Color::Red);
	}
	else {
		rectangle.setFillColor(sf::Color(255, 255, 0, 128));
		rectangle.setOutlineColor(Color::Yellow);
	}
}

void Slot::draw(RenderWindow& window) {
	window.draw(rectangle);
}