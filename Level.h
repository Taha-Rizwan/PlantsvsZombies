#pragma once
#pragma once
#ifndef GameState_H
#include "GameState.h"

class Level {
protected:
	int level, numOfZombies, waves, plantOptions, zombieOptions;
	int numOfRewards, numOfChallenges;
	std::string* rewards, * challenges;
	std::string name;
	sf::Text* challengesText, * rewardsText;
	bool roundStart, nextLevel;
	sf::Font font;
	sf::Texture buttonTexture;
	sf::Sprite button;
public:
	Level(int level, int numOfZombies, int plantOptions, int zombieOptions, int numOfRewards, int numOfChallenges, std::string* rewards, std::string* challenges, std::string name);
	virtual void createBack(sf::RenderWindow& window) = 0;
	virtual void displayChallenges(sf::RenderWindow& window, sf::Event event) = 0;
	virtual void displayRewards(sf::RenderWindow& window, sf::Event event) = 0;
	virtual void displayLevel(sf::RenderWindow& window, sf::Event event) = 0;
	virtual ~Level() {}
};

#endif