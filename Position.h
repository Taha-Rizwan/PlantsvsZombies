#pragma once
class Position {
protected:
	float pos[2];

public:
	Position(float x, float y);

	float* getPos();
	void setPos(float x, float y);
	void move(float x, float y =0);
};