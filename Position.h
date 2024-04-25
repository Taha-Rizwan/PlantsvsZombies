#pragma once
class Position {
protected:
	int pos[2];

public:
	Position(int x, int y);

	int* getPos();
	void setPos(int x, int y);
};