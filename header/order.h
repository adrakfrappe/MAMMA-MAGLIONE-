#pragma once
#include "SFML/Graphics.hpp"
#include <string>
#include <vector>
using namespace sf;
using namespace std;
class Order
{

	Text text2;
	Text text;
	vector<string> toppings;
	vector<string> salad;
	vector<string> flavours;

public:
	Order(Font& font);
	void generateRandom();
	void generateDifferentFrom(int excludeType);
	const vector<string>& getToppings() const { return toppings; }
	const vector<string>& getSalad() const { return salad; }
	const vector<string>& getFlavours() const { return flavours; }
	int getOrderType() const {
		if (!toppings.empty()) return 0;  // pizza
		if (!salad.empty()) return 1;     // salad
		if (!flavours.empty()) return 2;  // milkshake
		return -1;
	}
	void draw(RenderWindow& window);;
}; 