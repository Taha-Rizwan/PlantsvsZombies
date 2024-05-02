#include"GameState.h"

//GameState Constructor
GameState::GameState() :rows(5), columns(9),lives(4),score(0),economy(0),currentZombies(10) {
	grid = new Slot **[rows];
	for (int i = 0;i < rows;i++) {
		grid[i] = new Slot*[columns];
		for (int j = 0;j < columns;j++) {
			grid[i][j] = new Slot((250 + j * 80), (75 + i * 100));
		}
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

//Destructors
GameState::~GameState() {

}
