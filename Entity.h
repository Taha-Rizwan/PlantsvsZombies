#pragma once
#include <SFML/Graphics.hpp>
#include<iostream>
#include"Position.h"
using namespace std;
using namespace sf;

class Entity {
protected:
	Position pos;
	bool exists;
	int tolerance;
	string name;
	Sprite sprites;
	Clock clock;
public:
	void hit(int damage);
	bool getExists()const;
};