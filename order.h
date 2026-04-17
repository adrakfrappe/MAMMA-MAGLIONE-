#pragma once
#include "SFML/Graphics.hpp"
#include <string>
#include <vector>
using namespace sf;
using namespace std;
class Order
{
	RectangleShape box;
	Text text;
	vector<string> toppings;
public:
	Order(Font& font);
	void generateRandom();
	void draw(RenderWindow& window);;
};