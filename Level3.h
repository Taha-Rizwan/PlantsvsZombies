/*
	Muhammad Taha Rizwan 23I-0664
	Muhammad Aqib 23I-0670
	Section - G
*/
#pragma once
#ifndef GameState_H
#include"Level.h"
class Level3 :public Level {

public:
	//Level 3 Sunflower Fields with limited grid
	Level3();
	virtual void createBack(sf::RenderWindow& window);
	virtual void displayChallenges(sf::RenderWindow& window, sf::Event event);
	virtual void displayLevel(sf::RenderWindow& window, sf::Event event,bool state,int& score);
};

#endif