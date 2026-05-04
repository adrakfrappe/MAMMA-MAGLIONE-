#pragma once
#include "SFML/Graphics.hpp"

using namespace sf;
using namespace std;
class Ingredients
{
	Texture texture;
	Sprite sprite;
	Vector2f spawnposition;
public:
	Ingredients(const string& filename, Vector2f pos);
	void draw(RenderWindow& window);
	Sprite& getSprite();
	void respawn();


};
