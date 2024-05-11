#include "Level1.h"
#include "iostream"
Level1::Level1() : Level(1, 10, 3, 1, "Beginner's Garden","Wallnut Unlocked","Limited Plant Selection","Slow Zombie Waves") {

}

void Level1::createBack(sf::RenderWindow& window) {
	//Drawing the background
	sf::Image map_image;
	map_image.loadFromFile("./SFML/Images/day.png");
	sf::Texture map;
	map.loadFromImage(map_image);
	sf::Sprite s_map;
	s_map.setTexture(map);
	s_map.setPosition(0, 0);
	if (!roundStart || (roundStart && gameState.endRound()))
		s_map.setColor(sf::Color(255, 255, 255, 128));
	else
		s_map.setColor(sf::Color(255, 255, 255, 255));
	window.draw(s_map);
}

void Level1::displayChallenges(sf::RenderWindow& window, sf::Event event) {



	for (int i = 0; i < 2; i++) {
		window.draw(challengesText[i]);
	}
	window.draw(button);
	window.draw(nameText);
	if (event.type == sf::Event::MouseButtonPressed) {
		sf::Vector2f mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));
		if (button.getGlobalBounds().contains(mouse)) {
			roundStart = true;
			int* numZombies = new int[numOfZombies];
			numZombies[0] = numOfZombies;
		
			gameState.startRound(numZombies, numOfZombies);
		}
	}

}
void Level1::displayLevel(sf::RenderWindow& window, sf::Event event) {
	createBack(window);
	if (!roundStart)
		displayChallenges(window,event);
	if (roundStart && !gameState.endRound()) {
		gameState.gameplay(window, event);
		
	}
	else if (roundStart && gameState.endRound())
		displayRewards(window, event);
	
}