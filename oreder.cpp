//order.cpp
#include "game.h"
#include <cstdlib>
#include <ctime>
using namespace std;
using namespace sf;
Order::Order(Font& font)
{
   
    text.setFont(font);
    text.setCharacterSize(22);
    text.setFillColor(Color::Black);
    text.setPosition(100, 230);
    text2.setFont(font);
    text2.setCharacterSize(22);
    text2.setFillColor(Color::Black);
    text2.setPosition(500, 350);
    text2.setString("ok!coming right\nup play abdullah\n sajid's\nstreetfighter till\nI prepare\nyour pizza");
   
    

    srand(static_cast<unsigned>(time(nullptr))); // seed random once
    generateRandom();
}
void Order::generateRandom()
{
    int choice= rand()%3;
    if (choice == 0) {
        static const char* toppinglist[] = { "olives","mushrooms","onions","cheese","pepperoni","sausage" };
        toppings.clear();
        int numtoppings = 2 + rand() % 5; // 2 to 6 toppings
        string ordertext = "pizza with\n";
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
    else if (choice == 1)
    {
        {

            static const char* saladlist[] = {
                "lettuce",          // always included
                "salad dressing",   // always included
                "olives",
                "onions",
                "tomatoes",
                "chicken",
                "cucumbers",
                "mustard"          
            };
            salad.clear();
            salad.push_back("lettuce");
            salad.push_back("salad dressing");
            int numExtraToppings = 1 + rand() % 4; 

            string ordertext = "salad with\nlettuce\nsalad dressing\n";

            for (int i = 0; i < numExtraToppings; i++)
            {
                int toppingindex = 2+ rand() %6 ; 

                salad.push_back(saladlist[toppingindex]);
                ordertext += saladlist[toppingindex];
                if (i < numExtraToppings - 1)
                    ordertext += '\n';
            }

            text.setString(ordertext);
        }

    }
    else if (choice == 2)
    {
        static const char* flaovourslist[] = {"bananas","strawberries","mangoes","vanilla icecream","chocolate icecream","tutifruti icecream"};
        flavours.clear();
        flavours.clear();
        string ordertext = "milkshake with:\n";
        int fruitCount = 1 + rand() % 2;
        for (int i = 0; i < fruitCount; i++)
        {
            int toppingindex = rand() % 3; 
            flavours.push_back(flaovourslist[toppingindex]);
            ordertext += flaovourslist[toppingindex];
            ordertext += "\n"; 
        }
        int iceCreamCount = 1 + rand() % 2;
        for (int i = 0; i < iceCreamCount; i++)
        {
            int toppingindex = 3 + (rand() % 3);
            flavours.push_back(flaovourslist[toppingindex]);
            ordertext += flaovourslist[toppingindex];
            ordertext += "\n";
        }
        text.setString(ordertext);
    }
}
void Order::draw(sf::RenderWindow& window)
{
    window.draw(text);
    window.draw(text2);
}