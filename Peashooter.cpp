#include "Peashooter.h"

Peashooter::Peashooter(int x, int y) : Plant(x,y, 100, "./SFML/images/peashooter.png", "Peashooter", 27.5, 32.5, 10, 50), Shooter(x+40,y+5, 3, 5, "./SFML/images/peashooterBullet.png", 10, 15) {}