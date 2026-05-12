//uimanager.h
#pragma once
#include "SFML/Graphics.hpp"
#include "button.h"
#include <vector>
class UImanager 
{
	std::vector<Button> buttons; // vector of buttons
public:
	void addbutton(const Button& button);
	void draw(RenderWindow& window);
	void handleEvents(RenderWindow& window, Event& event, int& clickedIndex);
	void update(RenderWindow& window);
	void clearbutton();
};