#include "order.h"
#include <cstdlib>
#include <ctime>
using namespace std;
using namespace sf;
Order::Order(Font& font)
{
    box.setSize({ 250, 200});
    box.setFillColor(sf::Color::Red);
    box.setPosition(530, 20);

    text.setFont(font);
    text.setCharacterSize(20);
    text.setFillColor(sf::Color::Black);
    text.setPosition(540, 30);

    srand(static_cast<unsigned>(time(nullptr))); // seed random once
    generateRandom();
}
void Order::generateRandom()
{
    static const char* toppinglist[] = { "olives","mushrooms","onions","cheese","pepperoni","sausage" };
    toppings.clear();
	int numtoppings = 2 + rand() % 5; // 2 to 6 toppings
    string ordertext = "Order:"; 
    for (int i = 0; i < numtoppings; i++)
    {
		int toppingindex = rand() % 6; // 0 to 5 in toppinglist
		toppings.push_back(toppinglist[toppingindex]);
        ordertext += toppinglist[toppingindex];
        if (i < numtoppings - 1)
			ordertext += '\n';
    }
	text.setString(ordertext);
}
void Order::draw(sf::RenderWindow& window)
{
    window.draw(box);
    window.draw(text);
}