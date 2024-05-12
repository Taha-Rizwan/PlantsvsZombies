/*
	Muhammad Taha Rizwan 23I-0664
	Muhammad Aqib 23I-0670
	Section - G
*/

#pragma once
#ifndef GameState_H
#include"Level.h"
class Level4 :public Level {
	sf::Texture fogTexture;
	sf::Sprite fog[3];
	sf::Clock fogClock;
public:
	//Level 4 foggy fields with fog
	Level4();
	virtual void createBack(sf::RenderWindow& window);
	virtual void displayChallenges(sf::RenderWindow& window, sf::Event event);
	virtual void displayLevel(sf::RenderWindow& window, sf::Event event,bool state,int& score);
	void displayFog(sf::RenderWindow& window);
};

#endif