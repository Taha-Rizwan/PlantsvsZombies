/*
	Muhammad Taha Rizwan 23I-0664
	Muhammad Aqib 23I-0670
	Section - G
*/

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
	//Plant Class from which all plants inherit from
	Plant(int x, int y, int tolerance, std::string texturePath, std::string name, double textureX, double textureY,int waitingTime, int cost, int sprites,std::string cardSpritePath);
	int getCost();
	//Get Availibility of plant based on waitTime before you can purchase it
	bool getAvailable();
	int getTolarence();
	//SPawn Plant if bought on the grid
	void spawn(int x, int y);
	
	sf::Sprite* getCardSprite();
	virtual ~Plant() {}
};

#endif