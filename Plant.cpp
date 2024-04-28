#include "Plant.h"

Plant::Plant(int x, int y, int tolerance, string texturePath, string name, int textureX, int textureY, int waitingTime, int cost):Entity(x, y, tolerance, texturePath, name, textureX, textureY), waitingTime(waitingTime),cost(cost) {}


int Plant::getCost() {
	return cost;
}
int Plant::getWaitingTime() {
	return waitingTime;
}