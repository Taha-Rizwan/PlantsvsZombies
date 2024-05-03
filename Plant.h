#pragma once
#ifndef Entity_H
#include"Entity.h"
using namespace std;

class Plant:public Entity {
protected:
	int cost, waitingTime;
	Sprite cardSprite;
	Texture cardTexture;
public:
	Plant(int x, int y, int tolerance, string texturePath, string name, double textureX, double textureY,int waitingTime, int cost, int sprites);
	int getCost();
	int getWaitingTime();
	void displayCard(RenderWindow& window) {

	}
	Sprite& getSprite();
	virtual ~Plant() {}
};

#endif