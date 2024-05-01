#pragma once
#ifndef Entity_H
#include"Entity.h"
using namespace std;

class Plant:public Entity {
protected:
	int cost, waitingTime;
public:
	Plant(int x, int y, int tolerance, string texturePath, string name, double textureX, double textureY,int waitingTime, int cost, int sprites);
	int getCost();
	int getWaitingTime();
	virtual ~Plant() {}
};

#endif