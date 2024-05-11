#pragma once
#ifndef GameState_H
#include"Level.h"
class Level3 :public Level {

public:
	Level3();
	virtual void createBack(sf::RenderWindow& window);
	virtual void displayChallenges(sf::RenderWindow& window, sf::Event event);
	virtual void displayLevel(sf::RenderWindow& window, sf::Event event);
};

#endif