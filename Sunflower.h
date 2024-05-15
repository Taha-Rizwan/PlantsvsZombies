/*
	Muhammad Taha Rizwan 23I-0664
	Muhammad Aqib 23I-0670
	Section - G
*/
	
#pragma once
#include"Plant.h"
#include"Sun.h"
class Sunflower: public Plant {
	int waitTime;
	bool produceSun;
	Sun* sun;
	sf::Clock sClock;
public:
	//Sunflower Class
	Sunflower(int x, int y);
	
	bool getProduceSun()const;
	//Produces sun after a certain time
	Sun* produce();
	//Restart the clock
	void restartClock() {
		sClock.restart();
	}
};