#include "Level3.h"
#include "iostream"
Level3::Level3() : Level(3, 25, 5, 4, "Sunflower Fields","Repeater Unlocked","Limited PLacement for plants","Focus on Sunflower", true) {
	levelMusic.openFromFile("./SFML/Music/3.mp3");
	levelMusic.setLoop(true);
}

void Level3::createBack(sf::RenderWindow& window) {
	//Drawing the background
	sf::Image map_image;
	map_image.loadFromFile("./SFML/Images/limitedbg.jpg");
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

void Level3::displayChallenges(sf::RenderWindow& window, sf::Event event) {



	for (int i = 0; i < 2; i++) {
		window.draw(challengesText[i]);
	}
	window.draw(button);
	window.draw(nameText);
	if (event.type == sf::Event::MouseButtonPressed) {
		sf::Vector2f mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));
		if (button.getGlobalBounds().contains(mouse)) {
			roundStart = true;
			int* numZombies = new int[2];
			numZombies[0] = 3;
			numZombies[1] = 2;

			gameState.startRound(numZombies, 2);
		}
	}

}
void Level3::displayLevel(sf::RenderWindow& window, sf::Event event,bool state) {
	createBack(window);
	if (!roundStart)
		displayChallenges(window, event);
	if (roundStart && !gameState.endLevel()) {
		gameState.gameplay(window, event,state);
		if (gameState.endRound()) {
			waves++;
			if (waves == 1) {
				int* numZombies = new int[3];
				numZombies[0] = 5;
				numZombies[1] = 3;
				numZombies[2] = 2;
				gameState.startRound(numZombies, 3);
			}
			else if (waves == 2) {
				int* numZombies = new int[4];
				numZombies[0] = 3;
				numZombies[1] = 2;
				numZombies[2] = 3;
				numZombies[3] = 2;
				gameState.startRound(numZombies, 4);

			}
			waveClock.restart();
		}
		displayWave(window);
	}
	else if (roundStart && gameState.endLevel())
	{
		if (levelMusic.getStatus() == sf::SoundSource::Status::Playing)
			levelMusic.stop();
		displayRewards(window, event);

	}
}