#include <iostream>
#include "Peashooter.h"
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
	map_image.loadFromFile("./SFML/Images/backwindow.jpg");
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
	RenderWindow window(VideoMode(1200, 700), "Plants Vs Zombies");
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

	Peashooter pea(410, 175);
	Bullet** bullets = new Bullet*[100];
	int i = 0;
	while (window.isOpen())
	{
	
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		//If a bullet is shot it gets saved to the bullets array, and boom boom
		bullets[i] = pea.shoot();
		if (bullets[i] != nullptr) {
		
			i++;
		}
		
		//Create a background
		
		createBack(window);
		createMap(window);
		for (int j = 0; j < i; j++) {
			if(bullets[j]->getExists())
				bullets[j]->draw(window);
		}
		//If you don't draw stuff here after createBack and createMap IT WON'T DRAW
		pea.draw(window, 27.5, 32.5);
		window.setSize(sf::Vector2u(1100, 680));
		window.display();
	}
	return 0;
}