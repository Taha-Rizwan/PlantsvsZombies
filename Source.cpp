#include <iostream>
#include"headers.h"
#include <ctime>

//#include"../SFML/Images/"
using namespace sf;
using namespace std;

int x = 0;
int y = 1;
//Drawing the background
void createBack(RenderWindow& window) {
	//Drawing the background
	Image map_image;
	map_image.loadFromFile("./SFML/Images/day.png");
	Texture map;
	map.loadFromImage(map_image);
	Sprite s_map;
	s_map.setTexture(map);
	s_map.setPosition(0, 0);
	window.draw(s_map);
}

//Drawing the map
void createMap(RenderWindow& window) {
	//Drawing a map
	Image map_image;//объект изображения для карты
	map_image.loadFromFile("./SFML/Images/grid.png");//load the file for the map
	Texture map;
	map.loadFromImage(map_image);
	Sprite s_map;
	s_map.setTexture(map);
	s_map.setPosition(300, 160);

	window.draw(s_map);
}


int main()
{
	//Create a window, n*n
	RenderWindow window(VideoMode(1400, 600), "Plants Vs Zombies");
	//Game icon
	Image icon;
	if (!icon.loadFromFile("./SFML/Images/icon.png"))
	{
		return 1;
	}
	window.setIcon(32, 32, icon.getPixelsPtr());

	///////////////////////////////////////

	//Game field (5*9)
	//Point 137*79 - leftmost point
	//length 41; width 53
	const int ROWS = 5;
	const int COLS = 9;

	bool FIELD_GAME_STATUS[ROWS][COLS];

	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			FIELD_GAME_STATUS[i][j] = true;
		}
	}
	Clock clock;
	float time;
	//Y-axis starting point is 75, +100 to the slot below
	//X-axis starting point is 265, +80 to the slot on the right

	LawnMower** mowers = new LawnMower*[5];
	for (int i = 0;i < 5;i++) {
		mowers[i] = new LawnMower(120,55+100*i);
	}
	

	ZombieFactory zombieFactory(10);

	
	
	zombieFactory.addZombie(new FlyingZombie(1075,400));
	zombieFactory.addZombie(new Zombie(945, 75, 100, "./SFML/images/zombie.png", "Zombie", 46, 50, 10, 2, 0, false, 20, 7));
	zombieFactory.addZombie(new Zombie(1025, 275, 100, "./SFML/images/zombie.png", "Zombie", 46, 50, 10, 2, 0, false, 20, 7));
	zombieFactory.addZombie(new Zombie(1200, 75, 100, "./SFML/images/zombie.png", "Zombie", 46, 50, 10, 2, 0, false, 20, 7));

	Slot*** Grid = new Slot**[5];
	PlantFactory plantFactory(Grid);
	for (int i = 0; i < 5; i++) {
		Grid[i] = new Slot * [9];
		for (int j = 0; j < 9; j++) {
			Grid[i][j] = new Slot((250 + j*80), (75 + i*100));
			
		}
	}

	//Zombie* flyingZombie = new FlyingZombie(1075,300);
	//Zombie zombie(985,65,100,"./SFML/images/zombie.png", "Zombie", 46, 50, 10, 10, 0, false, 20, 7);
	


	while (window.isOpen())
	{

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
			
		}
		//If a bullet is shot it gets saved to the bullets array, and boom boom


		//Create a background

		createBack(window);
		//createMap(window);
	

		//If you don't draw stuff here after createBack and createMap IT WON'T DRAW(ok potner)
		//zombie.draw(window);
		//zombie.move();
		for (int i = 0;i < 5;i++) {
			mowers[i]->draw(window);
			mowers[i]->moveMower();
		}


		zombieFactory.drawZombies(window);
		zombieFactory.moveZombies();
		zombieFactory.detectCollision(plantFactory.getBullets(), plantFactory.getPlants(), mowers, plantFactory.getCurrentBullets(), plantFactory.getCurrentPlants(), 5);


		
		plantFactory.displayOptions(window,event);
		plantFactory.displayPlants(window);
		window.setSize(Vector2u(1100, 680));
		window.display();
	}
	return 0;
}