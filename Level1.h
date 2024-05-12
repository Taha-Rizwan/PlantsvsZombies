#pragma once
#ifndef GameState_H
#include"Level.h"
class Level1:public Level {

public:
	Level1();
	virtual void createBack(sf::RenderWindow& window);
	virtual void displayChallenges(sf::RenderWindow& window, sf::Event event);
	virtual void displayLevel(sf::RenderWindow& window, sf::Event event,bool state);
};

#endif