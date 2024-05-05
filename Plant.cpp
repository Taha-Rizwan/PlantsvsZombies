#include "Plant.h"

Plant::Plant(int x, int y, int tolerance, std::string texturePath, std::string name,double textureX, double textureY, int waitingTime, int cost, int sprites,std::string cardSpritePath):Entity(x, y, tolerance, texturePath, name, textureX, textureY, sprites), waitingTime(waitingTime),cost(cost) {
	cardTexture.loadFromFile(cardSpritePath);
	cardSprite.setTexture(cardTexture);
	cardSprite.setTextureRect(sf::IntRect(0, 0, 530, 340));
	cardSprite.setScale(0.3, 0.25);
	toggleExists();
}

sf::Sprite* Plant::getCardSprite() {
	return &cardSprite;
}

void Plant::spawn(int x, int y) {
	pos.pos[0] = x;
	pos.pos[1] = y;
	Entity::clock.restart();
	toggleExists();
}

int Plant::getCost() {
	return cost;
}
bool Plant::getAvailable() {
	if (waitClock.getElapsedTime().asSeconds() > waitingTime)
		return true;
	return false;
}