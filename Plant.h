#ifndef Entity_H
#define Entity_H
#include"Entity.h"

class Plant:public Entity {
protected:
	int cost, waitingTime;
	sf::Sprite cardSprite;
	sf::Texture cardTexture;
	sf::Clock waitClock;
public:
	Plant(int x, int y, int tolerance, std::string texturePath, std::string name, double textureX, double textureY,int waitingTime, int cost, int sprites,std::string cardSpritePath);
	int getCost();
	bool getAvailable();
	
	void spawn(int x, int y);
	sf::Sprite* getCardSprite();
	virtual ~Plant() {}
};

#endif