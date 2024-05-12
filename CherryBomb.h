#pragma once
#ifndef Plant_h
#include "Plant.h"
#include "SFML/Audio.hpp"
class CherryBomb : public Plant {
	int explodeTime;
	sf::SoundBuffer explosionBuffer;
	sf::Sound explosionSound;
public:
	CherryBomb(int x, int y);
	void draw(sf::RenderWindow& window, int y = 0);
	Position getPos();
};

#endif