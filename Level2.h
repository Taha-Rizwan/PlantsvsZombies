#pragma once
#ifndef GameState_H
#include"Level.h"
class Level2 :public Level {

public:
	Level2();
	virtual void createBack(sf::RenderWindow& window);
	virtual void displayChallenges(sf::RenderWindow& window, sf::Event event);
	virtual void displayLevel(sf::RenderWindow& window, sf::Event event,bool state,int& score);
};

#endif