#include "Position.h"

Position::Position(int x, int y) {
	pos[0] = x;
	pos[1] = y;
}

void Position::set(int x, int y) {
	pos[0] += x;
	pos[1] += y;
}