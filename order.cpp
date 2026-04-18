#include "order.h"
#include <cstdlib>
#include <ctime>
using namespace std;
using namespace sf;
Order::Order(Font& font)
{
   
    text.setFont(font);
    text.setCharacterSize(25);
    text.setFillColor(Color::Black);
    text.setPosition(100, 230);
    text2.setFont(font);
    text2.setCharacterSize(25);
    text2.setFillColor(Color::Black);
    text2.setPosition(500, 350);
    text2.setString("ok! coming right up \n play abdullah sajid's\nstreetfight till i prepare\n your pizza");
   
    

    srand(static_cast<unsigned>(time(nullptr))); // seed random once
    generateRandom();
}
void Order::generateRandom()
{
    static const char* toppinglist[] = { "olives","mushrooms","onions","cheese","pepperoni","sausage" };
    toppings.clear();
	int numtoppings = 2 + rand() % 5; // 2 to 6 toppings
    string ordertext = "make sure to add \n"; 
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
    window.draw(text);
    window.draw(text2);
}