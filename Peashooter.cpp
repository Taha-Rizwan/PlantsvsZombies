#include "Peashooter.h"

Peashooter::Peashooter(int x, int y) : Plant(x,y, 100, "./SFML/images/c/peashooter.png", "Peashooter", 71, 71, 10, 50, 13,"./SFML/images/peashooterCard.png"), Shooter(&(Plant::pos), 3, 20, "./SFML/images/peashooterBullet.png", 10, 15) {}