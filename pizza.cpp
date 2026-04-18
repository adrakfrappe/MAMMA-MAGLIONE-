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
			toppingslots[i][j].setRadius(int(cellSize / 4)); // leave some padding
			toppingslots[i][j].setFillColor(Color::Transparent);
			toppingslots[i][j].setOutlineColor(Color::Black);
			toppingslots[i][j].setOutlineThickness(2);
			toppingslots[i][j].setPosition(startX + j  * cellSize, startY + i * cellSize);
		}
	}
}
void Pizza::placeIngredient(sf::Vector2f mousePos, sf::Sprite ingredientSprite) {
	// Pizza center and radius
	sf::Vector2f pizzaCenter(350.f, 305.f); // center of 800x800 window
	float pizzaRadius = 200.f;              // adjust to match your dough size

	// Compute distance from center
	sf::Vector2f diff = mousePos - pizzaCenter;
	float distance = sqrt(diff.x * diff.x + diff.y * diff.y);

	// Only allow placement inside pizza circle
	if (distance <= pizzaRadius) {
		int cellSize = static_cast<int>(800 / 10); 
		int col = static_cast<int>(mousePos.x / cellSize);
		int row = static_cast<int>(mousePos.y / cellSize);

		float snappedX = col * cellSize + cellSize / 2;
		float snappedY = row * cellSize + cellSize / 2;

		ingredientSprite.setPosition(snappedX, snappedY);
		placedIngredients.push_back(ingredientSprite);
	}
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