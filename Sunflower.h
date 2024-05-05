#pragma once
#include"Plant.h"
#include"Sun.h"
class Sunflower: public Plant {
	int waitTime;
	bool produceSun;
	Sun* sun;
	sf::Clock sClock;
public:
	Sunflower(int x, int y);
	bool getProduceSun()const;
	Sun* produce();

};