//pizza.cpp
#include "game.h"
using namespace std;
using namespace sf;
Pizza::Pizza() {
	toppingslots.resize(rows, std::vector<sf::CircleShape>(cols));
}
void Pizza::generateMatrix(int screenWidth, int screenHeight)
{
	float gridWidth = cols * cellSize;
	float gridHeight = rows * cellSize;
	float startX = (screenWidth - gridWidth) / 2;
	float startY = (screenHeight - gridHeight) / 2;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			toppingslots[i][j].setRadius(int(cellSize / 4)); // leave some padding
			toppingslots[i][j].setFillColor(Color::Transparent);
			toppingslots[i][j].setOutlineColor(Color::Transparent);
			toppingslots[i][j].setOutlineThickness(2);
			toppingslots[i][j].setPosition(startX + j * cellSize, startY + i * cellSize);
		}
	}
}
void Pizza::generatematrix1(int screenWidth, int screenHeight)
{
	
	int milkCols = 3;
	int milkRows = 3;
	float milkCellSize = 50.f; 
	float blenderCenterX = 400.f;
	float blenderCenterY = 350.f;
	float gridWidth = milkCols * milkCellSize;
	float gridHeight = milkRows * milkCellSize;
	float startX = blenderCenterX - (gridWidth / 2.f);
	float startY = blenderCenterY - (gridHeight / 2.f);

	for (int i = 0; i < milkRows; i++)
	{
		for (int j = 0; j < milkCols; j++)
		{
			toppingslots[i][j].setRadius(15.f);
			toppingslots[i][j].setFillColor(Color::Transparent); // Semi-transparent black
			toppingslots[i][j].setOutlineColor(Color::Transparent);
			toppingslots[i][j].setOutlineThickness(1);
			toppingslots[i][j].setPosition(startX + j * milkCellSize, startY + i * milkCellSize);
		}
	}
}

void Pizza::placeIngredient(sf::Vector2f mousePos, sf::Sprite ingredientSprite) {
	// Pizza center and radius
	sf::Vector2f pizzaCenter(345.f, 220.f); // center of 800x800 window
	float pizzaRadius = 150.f;              // adjust to match your dough size

	// Compute distance from center
	sf::Vector2f diff = mousePos - pizzaCenter;
	float distance = sqrt(diff.x * diff.x + diff.y * diff.y);

	// Only allow placement inside pizza circle
	if (distance <= pizzaRadius) {
		int cellSize = static_cast<int>(800 / 13);
		int col = static_cast<int>(mousePos.x / cellSize);
		int row = static_cast<int>(mousePos.y / cellSize);

		float snappedX = col * cellSize + cellSize / 2;
		float snappedY = row * cellSize + cellSize / 2;

		ingredientSprite.setPosition(snappedX, snappedY);
		placedIngredients.push_back(ingredientSprite);
	}
}
void Pizza::placeSaladIngredient(sf::Vector2f mousePos, sf::Sprite ingredientSprite)
{
	// Pizza center and radius
	sf::Vector2f bowlCenter(340.f, 260.f); // center of 800x800 window
	float bowlRadius = 100.f;              // adjust to match your dough size

	// Compute distance from center
	sf::Vector2f diff = mousePos - bowlCenter;
	float distance = sqrt(diff.x * diff.x + diff.y * diff.y);

	// Only allow placement inside pizza circle
	if (distance <= bowlRadius) {
		int cellSize = static_cast<int>(800 / 13);
		int col = static_cast<int>(mousePos.x / cellSize);
		int row = static_cast<int>(mousePos.y / cellSize);
		float snappedX = col * cellSize + cellSize / 2;
		float snappedY = row * cellSize + cellSize / 2;
		ingredientSprite.setPosition(snappedX, snappedY);
		placedSaladIngredients.push_back(ingredientSprite);
	}
}
void Pizza::placemilkingredient(sf::Vector2f mousePos, sf::Sprite ingredientSprite)
{
	float blenderCenterX = 400.f;
	float blenderCenterY = 350.f;
	float milkCellSize = 50.f;
	int milkCols = 3;
	int milkRows = 3;

	float gridWidth = milkCols * milkCellSize;
	float gridHeight = milkRows * milkCellSize;
	float startX = blenderCenterX - (gridWidth / 2.f);
	float startY = blenderCenterY - (gridHeight / 2.f);

	// Check if mouse is within the general area of the jug
	sf::Vector2f diff = mousePos - sf::Vector2f(blenderCenterX, blenderCenterY);
	float distance = sqrt(diff.x * diff.x + diff.y * diff.y);

	if (distance <= 120.f) { // Radius of the jug opening
		// Calculate which row and column was clicked
		int col = static_cast<int>((mousePos.x - startX) / milkCellSize);
		int row = static_cast<int>((mousePos.y - startY) / milkCellSize);

		// Ensure indices are within our 3x2 bounds
		if (col >= 0 && col < milkCols && row >= 0 && row < milkRows) {
			float snappedX = startX + (col * milkCellSize) + (milkCellSize / 2.f);
			float snappedY = startY + (row * milkCellSize) + (milkCellSize / 2.f);

			// Center the sprite on the dot
			ingredientSprite.setOrigin(ingredientSprite.getLocalBounds().width / 2.f,
				ingredientSprite.getLocalBounds().height / 2.f);
			ingredientSprite.setPosition(snappedX, snappedY);

			placedmilkingredients.push_back(ingredientSprite);
		}
	}
}
void Pizza::addKetchupSplash(sf::Sprite ketchupbackground)
{
	sf::Vector2f bowlCenter(270.f, 230.f); // adjust to your salad bar layout
	ketchupbackground.setPosition(bowlCenter);
	ketchupbackground.setScale(0.5f, 0.5f);
	placedSaladIngredients.push_back(ketchupbackground);
}
void Pizza::addmustardSplash(Sprite mustardbackground) {
	sf::Vector2f bowlCenter(265.f, 225.f); // adjust to your salad bar layout
	mustardbackground.setPosition(bowlCenter);
	mustardbackground.setScale(0.5f, 0.5f);
	placedSaladIngredients.push_back(mustardbackground);
}
void Pizza::clearSaladIngredients() {
	placedSaladIngredients.clear();
}
void Pizza::clearpizzaingredients() {
	placedIngredients.clear();
}
void Pizza::clearmilk()
{
	placedmilkingredients.clear();
}
void Pizza::addblenderimage(Sprite blenderbackground)
{
	sf::Vector2f bowlCenter(270.f, 230.f); 
	blenderbackground.setPosition(bowlCenter);
	blenderbackground.setScale(1.0f, 1.0f);
	placedmilkingredients.push_back(blenderbackground);
	
}
void Pizza::draw(RenderWindow& window)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			window.draw(toppingslots[i][j]);
		}
	}
	for (auto& ing : placedIngredients) {
		window.draw(ing);
	}
}
void Pizza::drawsalad(RenderWindow& window)
{
	for (auto& ing : placedSaladIngredients) {
		window.draw(ing);
	}
}
void Pizza::drawmilk(RenderWindow& window)//for milk matrix
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			window.draw(toppingslots[i][j]);
		}
	}
	for (auto& ing : placedmilkingredients) {
		window.draw(ing);
	}
}