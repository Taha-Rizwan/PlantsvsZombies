#pragma once
#pragma once
#ifndef GameState_H
#include "GameState.h"

class Level {
protected:
	int level, numOfZombies, waves, plantOptions, zombieOptions;
	std::string rewards, challenges[2];
	std::string name;
	sf::Text* challengesText, * rewardsText;
	sf::Text nameText;
	bool roundStart, nextLevel;
	sf::Font font;
	sf::Texture buttonTexture,nextButtonTexture,newWaveText;
	sf::Sprite button,nextButton,newWave;
	sf::Clock waveClock;
	GameState gameState;
public:
	Level(int level, int numOfZombies, int plantOptions, int zombieOptions, std::string name, std::string rewards, std::string challenges1, std::string challenges2, bool limited = false);
	virtual void createBack(sf::RenderWindow& window) = 0;
	void displayWave(sf::RenderWindow& window);
	virtual void displayChallenges(sf::RenderWindow& window, sf::Event event) = 0;
	virtual void displayRewards(sf::RenderWindow& window, sf::Event event);
	virtual void displayLevel(sf::RenderWindow& window, sf::Event event) = 0;
	bool levelOver();
	virtual ~Level() {}
};

#endif