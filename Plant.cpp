#include "Plant.h"

Plant::Plant(int x, int y, int tolerance, string texturePath, string name,int textureX, int textureY, int waitingTime, int cost, int sprites):Entity(x, y, tolerance, texturePath, name, textureX, textureY, sprites), waitingTime(waitingTime),cost(cost) {}


int Plant::getCost() {
	return cost;
}
int Plant::getWaitingTime() {
	return waitingTime;
}