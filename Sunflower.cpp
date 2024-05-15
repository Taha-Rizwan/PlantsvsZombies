#include"Sunflower.h"
#include<iostream>
using namespace std;
Sunflower::Sunflower(int x, int y):waitTime(15),produceSun(true),Plant(x,y, 100,"./SFML/Images/sunflower.png","Sunflower", 71, 71,5,50,18,"./SFML/Images/sunflowerCard.png") {
	sun = nullptr;
	sClock.restart();
}

bool Sunflower::getProduceSun()const {
	return produceSun;
}

Sun* Sunflower::produce() {
	sun = nullptr;
	if (produceSun && exists){
		if (sClock.getElapsedTime().asSeconds() >= waitTime){
			sClock.restart();
			sun = new Sun(pos.pos[0]+20, pos.pos[1]-25);
		}
	}
	return sun;
}

