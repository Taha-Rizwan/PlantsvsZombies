#pragma once
#ifndef GameState_H
#include"Level.h"
class Level4 :public Level {
	sf::Texture fogTexture;
	sf::Sprite *fog;
	sf::Clock fogClock;
public:
	Level4();
	virtual void createBack(sf::RenderWindow& window);
	virtual void displayChallenges(sf::RenderWindow& window, sf::Event event);
	virtual void displayLevel(sf::RenderWindow& window, sf::Event event,bool state,int& score);
	void displayFog(sf::RenderWindow& window);
};

#endif