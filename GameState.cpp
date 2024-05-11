#include"GameState.h"

//GameState Constructor
GameState::GameState(int plantOptions, int zombies,bool limited) :plantOptions(plantOptions),rows(5), columns(9),lives(3),score(0),economy(0), zombieFactory(zombies),plantFactory(&economy, 45, limited),currentBullets(0),mowers(new LawnMower*[5]) {
	
	for (int i = 0; i < 5; i++) {
		mowers[i] = new LawnMower(200, 105 + 95 * i);
	}
	ecoBarTexture.loadFromFile("./SFML/images/ecobar.png");
	ecoBar.setTexture(ecoBarTexture);
	ecoBar.setTextureRect(sf::IntRect(0, 0, 677, 243));
	ecoBar.setColor(sf::Color(255, 255, 255, 128));
	ecoBar.setScale(0.3, 0.3);
	ecoBar.setPosition(1175,5);
	ecoFont.loadFromFile("./SFML/Fonts/serio.ttf");
	ecoText.setPosition(1230, 7.5);
	ecoText.setFont(ecoFont);
	ecoText.setCharacterSize(55);
	ecoText.setFillColor(sf::Color::Black);
	ecoText.setString(std::to_string(economy));
	heartTexture.loadFromFile("./SFML/images/heart.png");
	heart = new sf::Sprite[3];
	for (int i = 0; i < 3; i++) {
		heart[i].setTexture(heartTexture);
		heart[i].setTextureRect(sf::IntRect(0,0,512,512));
		heart[i].setScale(0.1, 0.1);
		heart[i].setPosition(1175 + i * 75, 550);
	}
}

//Getter for economy
int GameState::getEconomy()const {
	return economy;
}

//Setter for economy
void GameState::updateEconomy(int amount) {
	economy+= amount;
}

void GameState::spawnSun() {
	static sf::Clock sunClock;
	//Spawn Sun

}



void GameState::startRound(int* numOfZombies, int zombieOptions) {

	for (int i = 0; i < zombieOptions; i++) {
		for (int j = 0; j < numOfZombies[i]; j++) {
			if (i == 0) {
				zombieFactory.addZombie(new SimpleZombie(1000 + (rand() % 100), 75 + (100 * (rand() % 4)), 5 + j * 2));
			}
			else if (i == 1){
					zombieFactory.addZombie(new FootballZombie(1000 + (rand() % 100), 75 + (100 * (rand() % 4)), 8 + j * 2));
			}
			else if (i == 2) {
				zombieFactory.addZombie(new DancingZombie(1000 + (rand() % 100), 75 + (100 * (rand() % 4)), 10 + j * 2));
			}
			else if (i == 3) {
				zombieFactory.addZombie(new FlyingZombie(1000 + (rand() % 100), 75 + (100 * (rand() % 4)), 12 + j * 2));
			}
		}
	}
}
int GameState::getLives() {
	return lives;
}
bool GameState::endRound() {
	if (lives == 0)
		return true;
	return zombieFactory.allDead();
}

void GameState::displayEconomy(sf::RenderWindow& window) {
	ecoText.setString(std::to_string(economy));
	window.draw(ecoBar);
	window.draw(ecoText);
}

void GameState::gameplay(sf::RenderWindow& window, sf::Event& event) {
	static bool boom = false;

	for (int i = 0; i < 5; i++) {
		mowers[i]->draw(window);
		mowers[i]->moveMower();
	}
	zombieFactory.drawZombies(window);
	zombieFactory.moveZombies();
	zombieFactory.detectCollision(plantFactory.getBullets(), plantFactory.getPlants(), mowers, plantFactory.getCurrentBullets(), plantFactory.getCurrentPlants(), 5);
	if (plantFactory.isExplode()) {
		boom = true;
	}
	zombieFactory.detectExplosion(plantFactory.getExplosion(), window, &boom);
	plantFactory.displayOptions(window, event,plantOptions);
	plantFactory.displayPlants(window,event);
	
	displayEconomy(window);
	displayLives(window);
	sun.draw(window);
	sun.move();
	sun.appear();
	if (zombieFactory.deductLife())
		lives--;
	if (sun.collectSun(event, window))
		economy += 50;
}
void GameState::displayLives(sf::RenderWindow& window) {
	for (int i = 0; i < lives; i++) {
		window.draw(heart[i]);
	}
}

//Destructors
GameState::~GameState() {}
