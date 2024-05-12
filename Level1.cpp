#include "Level1.h"
#include "iostream"
Level1::Level1() : Level(1, 10, 3, 1, "Beginner's Garden","Wallnut Unlocked","Limited Plant Selection","Slow Zombie Waves") {
	levelMusic.openFromFile("./SFML/Music/1.mp3");
	levelMusic.setLoop(true);
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
	if (!roundStart || (roundStart && gameState.endLevel()))
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
			int* numZombies = new int[1];
			numZombies[0] = 2;
			
			gameState.startRound(numZombies, 1);
			levelMusic.play();
		}
	}

}
void Level1::displayLevel(sf::RenderWindow& window, sf::Event event,bool state) {
	createBack(window);
	if (!roundStart)
		displayChallenges(window,event);
	if (roundStart && !gameState.endLevel()) {
		gameState.gameplay(window, event,state);
		if (gameState.endRound()) {
			waves++;
			if (waves == 1) {
				int* numZombies = new int[1];
				numZombies[0] = 3;
				gameState.startRound(numZombies,1);
			}
			else if (waves == 2) {
				int* numZombies = new int[1];
				numZombies[0] = 5;
				
				gameState.startRound(numZombies, 1);
				
			}
			waveClock.restart();
		}
		displayWave(window);
	}
	else if (roundStart && gameState.endLevel()) {
		if (levelMusic.getStatus() == sf::SoundSource::Status::Playing)
			levelMusic.stop();
		displayRewards(window, event);
		
	}


	
}