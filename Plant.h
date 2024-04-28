#pragma once
#ifndef Entity_H
#include"Entity.h"
using namespace std;


class Plant:public Entity {
protected:
	int cost, waitingTime;

public:
	Plant(int x, int y, int tolerance, string texturePath, string name, int textureX, int textureY,  int waitingTime, int cost);
	int getCost();
	int getWaitingTime();

};

#endif