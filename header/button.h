#pragma once
#include "SFML/Graphics.hpp"
#include <string>
using namespace sf;
using namespace std;
class Button {
	RectangleShape shape; // the shape of the button
	Text label;
	// the text on the button
	Color normalColor; // the color of the button when it's idle
	Color hoverColor; // the color of the button when the mouse is hovering over it
public:
	Button(const sf::Vector2f& size, const sf::Vector2f& position,
		const std::string& text, sf::Font& font);
public:
	void draw(sf::RenderWindow& window);
	void update(const sf::Vector2i& mousePos);
	bool isClicked(const sf::Vector2i& mousePos, sf::Event& event);

	string getLabel() const
	{
		return label.getString();
	}
};
