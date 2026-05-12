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
	Button(const Vector2f& size, const Vector2f& position,const string& text, Font& font);
	void draw(RenderWindow& window);
	void update(const Vector2i& mousePos);
	bool isClicked(const Vector2i& mousePos, Event& event);
	string getLabel() const
	{
		return label.getString();
	}
};
