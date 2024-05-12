/*
	Muhammad Taha Rizwan 23I-0664
	Muhammad Aqib 23I-0670
	Section - G
*/

#pragma once
#ifndef GameState_H
#include "GameState.h"
#include "SFML/Audio.hpp"

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
	sf::Music levelMusic;
	sf::SoundBuffer winBuffer, loseBuffer;
	sf::Sound winSound, loseSound;
	GameState gameState;
	
public:
	//Abstract Level Class
	Level(int level, int numOfZombies, int plantOptions, int zombieOptions, std::string name, std::string rewards, std::string challenges1, std::string challenges2, bool limited = false);
	//Pure Virtual Function to create background of each class
	virtual void createBack(sf::RenderWindow& window) = 0;
	//Displays when there is a new wave
	void displayWave(sf::RenderWindow& window);
	//Pure virtual function to display challenges of current level and the start level function
	virtual void displayChallenges(sf::RenderWindow& window, sf::Event event) = 0;
	//Function to display level rewards and button to go to next level
	virtual void displayRewards(sf::RenderWindow& window, sf::Event event);
	virtual void displayLevel(sf::RenderWindow& window, sf::Event event,bool state,int& score) = 0;
	void update(float dt);
	//Check for if level is over
	bool levelOver();
	virtual ~Level() {}
};

#endif