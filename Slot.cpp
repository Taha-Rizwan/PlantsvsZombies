#include "Slot.h"

Slot::Slot(int x, int y):pos(x,y) {
	plant = nullptr;
	filled = false;
	rectangle.setSize(sf::Vector2f(80, 100));
	rectangle.setFillColor(sf::Color(255, 255, 0, 128));
	rectangle.setPosition(x, y);
	rectangle.setOutlineColor(sf::Color::White);
	rectangle.setOutlineThickness(1);
}

void Slot::toggleFilled() {
	filled = !filled;
	normalState();
}

void Slot::normalState() {
	if (filled) {
		rectangle.setFillColor(sf::Color(255, 0, 0, 128));
		//rectangle.setOutlineColor(sf::Color::Red);
	}
	else {
		rectangle.setFillColor(sf::Color(255, 255, 0, 128));
		rectangle.setOutlineColor(sf::Color::White);
	}
}

void Slot::checkFilled() {
	if (plant!=nullptr && !plant->getExists()) {
		plant = nullptr;
		toggleFilled();
	} 
	if (plant == nullptr && filled)
		toggleFilled();
}

void Slot::draw(sf::RenderWindow& window) {
	window.draw(rectangle);
}