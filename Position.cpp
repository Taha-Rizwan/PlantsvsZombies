#include "Position.h"

Position::Position(int x, int y) {
	pos[0] = x;
	pos[1] = y;
}

int* Position::getPos() {
	return pos;
}
void Position::setPos(int x, int y) {
	pos[0] = x;
	pos[1] = y;
}