#pragma once
#ifndef GameState_H
#include "GameState.h"

class Level {
	int level, numOfZombies, waves, plantOptions, zombieOptions;
	int numOfRewards, numOfChallenges;
	std::string* rewards,*challenges;
	std::string name;
	GameState gameState;
	sf::Text* challengesText,*rewardsText;
	bool roundStart, nextLevel;
	sf::Font font;
	sf::Texture buttonTexture;
	sf::Sprite button;
public:
	Level(int level,int numOfZombies,int plantOptions,int zombieOptions,int numOfRewards, int numOfChallenges,std::string* rewards,std::string* challenges,std::string name);
	void createBack(sf::RenderWindow& window);
	void displayChallenges(sf::RenderWindow& window, sf::Event event);
	void displayRewards(sf::RenderWindow& window, sf::Event event);
	void displayLevel(sf::RenderWindow& window, sf::Event event);
};

#endif