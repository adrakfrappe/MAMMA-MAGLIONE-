#include "pizza.h"
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
			toppingslots[i][j].setRadius(cellSize / 3); // leave some padding
			toppingslots[i][j].setFillColor(Color::Transparent);
			toppingslots[i][j].setOutlineColor(Color::Black);
			toppingslots[i][j].setOutlineThickness(2);
			toppingslots[i][j].setPosition(startX + j * cellSize, startY + i * cellSize);
		}
	}
}
void Pizza::placeIngredient(Vector2f mousePos, Sprite ingredientSprite)
{
	int cellSize = 100; // adjust to your grid size
	int col = static_cast<int>(mousePos.x / cellSize);
	int row = static_cast<int>(mousePos.y / cellSize);

	// snap to cell center
	float snappedX = col * cellSize + cellSize / 2;
	float snappedY = row * cellSize + cellSize / 2;

	ingredientSprite.setPosition(snappedX, snappedY);

	// store topping so it persists on pizza
	placedIngredients.push_back(ingredientSprite);
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