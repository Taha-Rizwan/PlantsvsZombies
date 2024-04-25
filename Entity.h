#include "Position.h"
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;
class Entity {
protected:
	Position pos;
	bool exists;
	int tolerance;
	string name;
	Sprite sprite;
	Texture texture;
	Clock clock;

public:
	Entity(int x, int y, int tolerance, string texturePath, string name, int textureX, int textureY);
	void draw(RenderWindow& window, int textureX, int textureY);
	void hit(int damage);
	bool getExists();
	void toggleExists();
	
};