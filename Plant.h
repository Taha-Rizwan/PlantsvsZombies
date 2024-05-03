#ifndef Entity_H
#define Entity_H
#include"Entity.h"

class Plant:public Entity {
protected:
	int cost, waitingTime;
	sf::Sprite cardSprite;
	sf::Texture cardTexture;
public:
	Plant(int x, int y, int tolerance, std::string texturePath, std::string name, double textureX, double textureY,int waitingTime, int cost, int sprites);
	int getCost();
	int getWaitingTime();
	void displayCard(sf::RenderWindow& window) {

	}
	sf::Sprite* getCardSprite();
	virtual ~Plant() {}
};

#endif