//pizza.h
#pragma once
#include "SFML/Graphics.hpp"
#include <vector>
using namespace sf;
using namespace std;
class Pizza
{
public:
	int rows = 4, cols = 4;
	float cellSize = 60;
	vector<vector<CircleShape>> toppingslots;
	vector<Sprite> placedIngredients;
	vector<string> placedIngredientNames;
	vector<Sprite> placedSaladIngredients;
	vector<string> placedSaladNames;
	vector<Sprite> placedmilkingredients;
	Pizza();
	void generateMatrix(int screenWidth, int screenHeight);
	void placeIngredient(Vector2f mousePos, Sprite ingredient);
	void draw(RenderWindow& window);
	void drawsalad(RenderWindow& window);
	void placeSaladIngredient(Vector2f mousePos, Sprite ingredient);
	vector<string> placedMilkNames;
	void addRanchSplash(Sprite ranchbackground);
	void addmustardSplash(Sprite mustardbackground);
	void clearSaladIngredients();
	void clearpizzaingredients();
	void addblenderimage(Sprite blenderbackground);//
	void generatematrix1(int screenWidth, int screenHeight);
	void placemilkingredient(Vector2f mousePos, Sprite ingredient);
	void drawmilk(RenderWindow& window);
	void clearmilk();

	void addIngredientName(const string& name);
	const vector<string>& getPlacedNames() const;
	void clearIngredientNames();

	void addSaladName(const string& name);
	const vector<string>& getPlacedSaladNames() const;
	void clearSaladNames();

	void addMilkName(const string& name);
	const vector<string>& getPlacedMilkNames() const;
	void clearMilkNames();
};