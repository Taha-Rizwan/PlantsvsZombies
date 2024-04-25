#include "Position.h"

Position::Position(float x, float y) {
	pos[0] = x;
	pos[1] = y;
}

float* Position::getPos() {
	return pos;
}
void Position::setPos(float x = 0, float y = 0) {
	pos[0] = x;
	pos[1] = y;
}
void Position::move(float x, float y) {
	pos[0] += x;
	pos[1] += y;
}