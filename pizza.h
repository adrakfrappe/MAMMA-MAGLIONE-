#pragma once
#include "SFML/Graphics.hpp"
#include <vector>
using namespace sf;
using namespace std;
class Pizza
{
public:
	int rows=4, cols=4;
	float cellSize=60;
	vector<vector<CircleShape>> toppingslots;
	vector<Sprite> placedIngredients;
	vector<Sprite> placedSaladIngredients;

public:
	Pizza();
	void generateMatrix(int screenWidth, int screenHeight);
	void placeIngredient(Vector2f mousePos, Sprite ingredient);
	void draw(RenderWindow& window);
	void drawsalad(RenderWindow& window);
	void placeSaladIngredient(Vector2f mousePos, Sprite ingredient);
	void addKetchupSplash(Sprite ketchupbackground);
	void addmustardSplash(Sprite ketchupbackground);
};