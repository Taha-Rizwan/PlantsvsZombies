#include"FootballZombie.h"

FootballZombie::FootballZombie(int x,int y): Zombie(x,y,40,"./SFML/Images/footballZombie.png","FootballZombie",20,36,20,2,0,false,20,7){
	sprite.setScale(2,2);
}

void FootballZombie::move() {
	static int x = 0;
	float time = moveClock.restart().asSeconds();
	if (x == 0) {
		pos.set(-speed*time, -speed*time);
		x++;
	}
	else if(x==1){
		pos.set(-speed*time, speed*time);
		x--;
	}
}