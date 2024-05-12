#include "Level4.h"
Level4::Level4() : Level(4, 30, 6, 4, "Foggy Forest","Snow Pea Unlocked for future use","Reduced Visiblity","Zombies emerge unexpectedly") {
	
	fogTexture.loadFromFile("./SFML/images/fog.png");

	for (int i = 0; i < 3; i++) {
		fog[i].setTexture(fogTexture);
		fog[i].setTextureRect(sf::IntRect(0, 0, 507, 1280));
		fog[i].setPosition(650 + i*100, 0);
		fog[i].setScale(0.5, 0.5);
	}
	
	levelMusic.openFromFile("./SFML/Music/4.mp3");
	levelMusic.setLoop(true);
}

void Level4::createBack(sf::RenderWindow& window) {
	//Drawing the background
	sf::Image map_image;
	map_image.loadFromFile("./SFML/Images/bgnight.jpg");
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

void Level4::displayChallenges(sf::RenderWindow& window, sf::Event event) {



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
			numZombies[0] = 5;
			numZombies[1] = 2;
			gameState.startRound(numZombies, 2);
			levelMusic.play();
		}
	}

}
void Level4:: displayFog(sf::RenderWindow& window) {
	static int opacity = 255;
	if (fogClock.getElapsedTime().asSeconds() >= 3) {
		fogClock.restart();
		opacity = 101 + rand() % 155;
	}
	for (int i = 0; i < 3; i++) {
		fog[i].setColor(sf::Color(255, 255, 255, opacity));
		window.draw(fog[i]);
	}
}
void Level4::displayLevel(sf::RenderWindow& window, sf::Event event,bool state,int& score) {
	createBack(window);
	if (!roundStart)
		displayChallenges(window, event);
	if (roundStart && !gameState.endLevel()) {
		gameState.gameplay(window, event,state,score);
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
				numZombies[0] = 5;
				numZombies[1] = 3;
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

	displayFog(window);
}