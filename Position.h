#pragma once
class Position {
public:
	float pos[2];
	Position(float x, float y);
	void move(float x, float y=0);
};