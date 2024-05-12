/*
	Muhammad Taha Rizwan 23I-0664
	Muhammad Aqib 23I-0670
	Section - G
*/
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
	//Draw Function for CHerrybomb
	void draw(sf::RenderWindow& window, int y = 0);
	//To get Position of Cherrybomb for Explosion
	Position getPos();
};

#endif