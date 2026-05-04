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

        int indices[6] = { 0, 1, 2, 3, 4, 5 };
        for (int i = 5; i > 0; i--) {
            int j = rand() % (i + 1);
            int temp = indices[i]; indices[i] = indices[j]; indices[j] = temp;
        }

        int numtoppings = 2 + rand() % 5;
        string ordertext = "pizza with\n";
        for (int i = 0; i < numtoppings; i++)
        {
            
            toppings.push_back(toppinglist[indices[i]]);
            ordertext += toppinglist[indices[i]];
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
                "ranch",   // always included
                "olives",
                "onions",
                "tomatoes",
                "chicken",
                "cucumbers",
                "mustard"          
            };
            salad.clear();
            salad.push_back("lettuce");
            salad.push_back("ranch");

            int saladIndices[6] = { 2, 3, 4, 5, 6, 7 };
            for (int i = 5; i > 0; i--) {
                int j = rand() % (i + 1);
                int temp = saladIndices[i]; saladIndices[i] = saladIndices[j]; saladIndices[j] = temp;
            }
            int numExtraToppings = 1 + rand() % 4; 

            string ordertext = "salad with\nlettuce\nranch\n";

            for (int i = 0; i < numExtraToppings; i++)
            {

                salad.push_back(saladlist[saladIndices[i]]);
                ordertext += saladlist[saladIndices[i]];
                if (i < numExtraToppings - 1)
                    ordertext += '\n';
            }

            text.setString(ordertext);
        }

    }
    else if (choice == 2)
    {
        static const char* flaovourslist[] = { "bananas","strawberries","mangoes","vanilla icecream","chocolate icecream","tutifruti icecream" };
        flavours.clear();
        string ordertext = "milkshake with:\n";

        int fruitIndices[3] = { 0, 1, 2 };
        for (int i = 2; i > 0; i--) {
            int j = rand() % (i + 1);
            int temp = fruitIndices[i]; fruitIndices[i] = fruitIndices[j]; fruitIndices[j] = temp;
        }
        int iceCreamIndices[3] = { 3, 4, 5 };
        for (int i = 2; i > 0; i--) {
            int j = rand() % (i + 1);
            int temp = iceCreamIndices[i]; iceCreamIndices[i] = iceCreamIndices[j]; iceCreamIndices[j] = temp;
        }

        vector<string> addedFlavours;

        int fruitCount = 1 + rand() % 2;
        for (int i = 0; i < fruitCount; i++)
        {
            string flavour = flaovourslist[fruitIndices[i]];
            bool alreadyAdded = false;
            for (const string& f : addedFlavours)
                if (f == flavour) { alreadyAdded = true; break; }
            if (!alreadyAdded) {
                flavours.push_back(flavour);
                ordertext += flavour;
                ordertext += "\n";
                addedFlavours.push_back(flavour);
            }
        }
        int iceCreamCount = 1 + rand() % 2;
        for (int i = 0; i < iceCreamCount; i++)
        {
            string flavour = flaovourslist[iceCreamIndices[i]];
            bool alreadyAdded = false;
            for (const string& f : addedFlavours)
                if (f == flavour) { alreadyAdded = true; break; }
            if (!alreadyAdded) {
                flavours.push_back(flavour);
                ordertext += flavour;
                ordertext += "\n";
                addedFlavours.push_back(flavour);
            }
        }
        text.setString(ordertext);
    }
}

void Order::generateDifferentFrom(int excludeType)
{
    // generate till different
    int choice;
    do {
        choice = rand() % 3;
    } while (choice == excludeType);

    // clear all
    toppings.clear();
    salad.clear();
    flavours.clear();

    // set choice and use the generation block
    if (choice == 0) {
        static const char* toppinglist[] = { "olives","mushrooms","onions","cheese","pepperoni","sausage" };
        int indices[6] = { 0,1,2,3,4,5 };
        for (int i = 5; i > 0; i--) {
            int j = rand() % (i + 1);
            int temp = indices[i]; indices[i] = indices[j]; indices[j] = temp;
        }
        int numtoppings = 2 + rand() % 5;
        string ordertext = "pizza with\n";
        for (int i = 0; i < numtoppings; i++) {
            toppings.push_back(toppinglist[indices[i]]);
            ordertext += toppinglist[indices[i]];
            if (i < numtoppings - 1) ordertext += '\n';
        }
        text.setString(ordertext);
    }
    else if (choice == 1) {
        static const char* saladlist[] = {
            "lettuce","ranch","olives","onions","tomatoes","chicken","cucumbers","mustard"
        };
        salad.push_back("lettuce");
        salad.push_back("ranch");
        int saladIndices[6] = { 2,3,4,5,6,7 };
        for (int i = 5; i > 0; i--) {
            int j = rand() % (i + 1);
            int temp = saladIndices[i]; saladIndices[i] = saladIndices[j]; saladIndices[j] = temp;
        }
        int numExtraToppings = 1 + rand() % 4;
        string ordertext = "salad with\nlettuce\nranch\n";
        for (int i = 0; i < numExtraToppings; i++) {
            salad.push_back(saladlist[saladIndices[i]]);
            ordertext += saladlist[saladIndices[i]];
            if (i < numExtraToppings - 1) ordertext += '\n';
        }
        text.setString(ordertext);
    }
    else if (choice == 2) {
        static const char* flaovourslist[] = { "bananas","strawberries","mangoes","vanilla icecream","chocolate icecream","tutifruti icecream" };
        string ordertext = "milkshake with:\n";
        int fruitIndices[3] = { 0,1,2 };
        for (int i = 2; i > 0; i--) {
            int j = rand() % (i + 1);
            int temp = fruitIndices[i]; fruitIndices[i] = fruitIndices[j]; fruitIndices[j] = temp;
        }
        int iceCreamIndices[3] = { 3,4,5 };
        for (int i = 2; i > 0; i--) {
            int j = rand() % (i + 1);
            int temp = iceCreamIndices[i]; iceCreamIndices[i] = iceCreamIndices[j]; iceCreamIndices[j] = temp;
        }
        vector<string> addedFlavours;
        int fruitCount = 1 + rand() % 2;
        for (int i = 0; i < fruitCount; i++) {
            string flavour = flaovourslist[fruitIndices[i]];
            bool already = false;
            for (const string& f : addedFlavours) if (f == flavour) { already = true; break; }
            if (!already) { flavours.push_back(flavour); ordertext += flavour + "\n"; addedFlavours.push_back(flavour); }
        }
        int iceCreamCount = 1 + rand() % 2;
        for (int i = 0; i < iceCreamCount; i++) {
            string flavour = flaovourslist[iceCreamIndices[i]];
            bool already = false;
            for (const string& f : addedFlavours) if (f == flavour) { already = true; break; }
            if (!already) { flavours.push_back(flavour); ordertext += flavour + "\n"; addedFlavours.push_back(flavour); }
        }
        text.setString(ordertext);
    }
}


void Order::draw(sf::RenderWindow& window)
{
    window.draw(text);
    window.draw(text2);
}