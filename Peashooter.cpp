#include "Peashooter.h"

Peashooter::Peashooter(int x, int y) : Plant(x,y, 100, "./SFML/images/c/peashooter.png", "Peashooter", 71, 71, 10, 50, 13), Shooter(x+40,y+5, 3, 5, "./SFML/images/peashooterBullet.png", 10, 15) {}