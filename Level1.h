#pragma once
#ifndef GameState_H
#include"Level.h"
class Level1:public Level {
	GameState gameState;
public:
	Level1(int level,int numOfZombies,int plantOptions,int zombieOptions,int numOfRewards, int numOfChallenges,std::string* rewards,std::string* challenges,std::string name);
	virtual void createBack(sf::RenderWindow& window);
	virtual void displayChallenges(sf::RenderWindow& window, sf::Event event);
	virtual void displayRewards(sf::RenderWindow& window, sf::Event event);
	virtual void displayLevel(sf::RenderWindow& window, sf::Event event);
};

#endif