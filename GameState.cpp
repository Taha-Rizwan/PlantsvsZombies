#include"GameState.h"

//GameState Constructor
GameState::GameState() :rows(5), columns(9),lives(5),score(0),economy(100), zombieFactory(10),plantFactory(&economy),currentBullets(0),mowers(new LawnMower*[5]) {
	
	for (int i = 0; i < 5; i++) {
		mowers[i] = new LawnMower(200, 105 + 95 * i);
	}
	ecoBarTexture.loadFromFile("./SFML/images/ecobar.png");
	ecoBar.setTexture(ecoBarTexture);
	ecoBar.setTextureRect(sf::IntRect(0, 0, 677, 243));
	ecoBar.setColor(sf::Color(255, 255, 255, 192));
	ecoBar.setScale(0.3, 0.3);
	ecoBar.setPosition(1175,5);
	ecoFont.loadFromFile("./SFML/Fonts/serio.ttf");
	ecoText.setPosition(1230, 7.5);
	ecoText.setFont(ecoFont);
	ecoText.setCharacterSize(55);

	ecoText.setString(std::to_string(economy));
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

void GameState::startRound() {
	zombieFactory.addZombie(new SimpleZombie(945, 75));
	zombieFactory.addZombie(new SimpleZombie(1025, 275));
	zombieFactory.addZombie(new SimpleZombie(1200, 75));
	zombieFactory.addZombie(new SimpleZombie(945, 75));
	zombieFactory.addZombie(new SimpleZombie(1025, 275));
	zombieFactory.addZombie(new SimpleZombie(1200, 75));
	zombieFactory.addZombie(new SimpleZombie(945, 75));
	zombieFactory.addZombie(new SimpleZombie(1025, 275));
	zombieFactory.addZombie(new SimpleZombie(1200, 75));
	zombieFactory.addZombie(new SimpleZombie(945, 75));
	

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
	plantFactory.displayOptions(window, event);
	plantFactory.displayPlants(window);
	suns.draw(window);
	displayEconomy(window);
	suns.move();
	suns.collectSun(event);
}

//Destructors
GameState::~GameState() {

}
