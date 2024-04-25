#include "Position.h"

Position::Position(float x, float y) {
	pos[0] = x;
	pos[1] = y;
}

void Position::move(float x, float y) {
	pos[0] += x;
	pos[1] += y;
}