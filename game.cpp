#include "game.h"
#include <iostream>
#include "button.h"
#include "pizza.h"
#include "audio.h"
#include "ingrediens.h"   // your Ingredients class
using namespace std;
using namespace sf;

Game::Game(sf::RenderWindow& win)
    : window(win),
    pizza(),
    olives("C:\\Users\\ghazaal\\source\\repos\\mamma maglione 2.6\\assets\\olive-.png", { 30, 480 }),
    cheese("C:\\Users\\ghazaal\\source\\repos\\mamma maglione 2.6\\assets\\cheese-.png", { 550, 480 }),
    sausage("C:\\Users\\ghazaal\\source\\repos\\mamma maglione 2.6\\assets\\sausage-.png", { 670, 480}),
    mushrooms("C:\\Users\\ghazaal\\source\\repos\\mamma maglione 2.6\\assets\\mushroom-.png", { 170, 480}),
    pepperoni("C:\\Users\\ghazaal\\source\\repos\\mamma maglione 2.6\\assets\\pep-.png", { 420, 480 }),
    onions("C:\\Users\\ghazaal\\source\\repos\\mamma maglione 2.6\\assets\\onion-.png", { 300, 480 })
{
    state = gamestate::HOMEPAGE;

    // Load font
    if (!font.loadFromFile("C:\\Users\\ghazaal\\source\\repos\\mamma maglione 2.6\\assets\\arial-font\\arial.ttf")) {
        std::cout << "Error loading font!" << std::endl;
    }

    // Add buttons
    uimanager.addbutton(Button({ 200, 60 }, { 20, 20 }, "Order", font));
    uimanager.addbutton(Button({ 200, 60 }, { 20, 100 }, "Kitchen", font));
    uimanager.addbutton(Button({ 200, 60 }, { 20, 180 }, "Oven", font));

    // Load textures
    orderBgTex.loadFromFile("C:\\Users\\ghazaal\\source\\repos\\mamma maglione 2.6\\assets\\oder.jpeg");
    cookingBgTex.loadFromFile("C:\\Users\\ghazaal\\source\\repos\\mamma maglione 2.6\\assets\\cooking station.jpeg");
    ovenBgTex.loadFromFile("C:\\Users\\ghazaal\\source\\repos\\mamma maglione 2.6\\assets\\oven.jpeg");
    homeBgTex.loadFromFile("C:\\Users\\ghazaal\\source\\repos\\mamma maglione 2.6\\assets\\main.jpeg");

    // Assign textures
    orderBackground.setTexture(orderBgTex);
    cookingBackground.setTexture(cookingBgTex);
    ovenBackground.setTexture(ovenBgTex);
    homeBackground.setTexture(homeBgTex);

    // Scale sprites
    auto scaleToWindow = [&](sf::Sprite& sprite, sf::Texture& tex) {
        sf::Vector2u texSize = tex.getSize();
        float scaleX = 800.0f / texSize.x;
        float scaleY = 800.0f / texSize.y;
        sprite.setScale(scaleX, scaleY);
        };

    scaleToWindow(orderBackground, orderBgTex);
    scaleToWindow(cookingBackground, cookingBgTex);
    scaleToWindow(ovenBackground, ovenBgTex);
    scaleToWindow(homeBackground, homeBgTex);

    currentOrder = new Order(font);
    pizza.generateMatrix(800, 600); // center in 800x800 window

    // Start background music
    audio.start("C:\\Users\\ghazaal\\source\\repos\\mamma maglione 2.6\\assets\\Mambo Italiano.ogg");
}

void Game::run() {
    while (window.isOpen()) {
        handleEvents();
        update();
        render();
    }
}

void Game::handleEvents() {
    Event event;
    while (window.pollEvent(event)) {
        if (event.type == Event::Closed) {
            window.close();
        }

        int clickedIndex;
        uimanager.handleEvents(window, event, clickedIndex);

        if (clickedIndex == 0) {
            state = gamestate::ORDER_SCREEN;
            currentOrder->generateRandom(); // Generate a new random order when the button is clicked
        }
        else if (clickedIndex == 1) state = gamestate::COOKING_SCREEN;
        else if (clickedIndex == 2) state = gamestate::OVEN_SCREEN;
    }
}

void Game::update() {
    uimanager.update(window);   // hover updates every frame
    // later: drag/drop logic for ingredients
}

void Game::render() {
    window.clear();

    if (state == gamestate::HOMEPAGE) {
        window.draw(homeBackground);
    }
    else if (state == gamestate::ORDER_SCREEN) {
        window.draw(orderBackground);
        currentOrder->draw(window);
    }
    else if (state == gamestate::COOKING_SCREEN) {
        window.draw(cookingBackground);
        pizza.draw(window);

        // Draw ingredient bowls
        cheese.draw(window);
        sausage.draw(window);
        mushrooms.draw(window);
        pepperoni.draw(window);
        olives.draw(window);
        onions.draw(window);
    }
    else if (state == gamestate::OVEN_SCREEN) {
        window.draw(ovenBackground);
    }

    uimanager.draw(window);
    window.display();
}
