#include "game.h"
#include <iostream>
#include "button.h"
#include "pizza.h"
#include "audio.h"
#include "order.h"
#include "ingrediens.h"   // your Ingredients class
using namespace std;
using namespace sf;

Game::Game(RenderWindow& win)
    : window(win),
    pizza(),
    olives("C:\\Users\\ghazaal\\source\\repos\\mamma maglione 2.6\\assets\\olive-.png", { 30, 500 }),
    cheese("C:\\Users\\ghazaal\\source\\repos\\mamma maglione 2.6\\assets\\cheese-.png", { 550, 500 }),
    sausage("C:\\Users\\ghazaal\\source\\repos\\mamma maglione 2.6\\assets\\sausage-.png", { 670, 500}),
    mushrooms("C:\\Users\\ghazaal\\source\\repos\\mamma maglione 2.6\\assets\\mushroom-.png", { 170, 500}),
    pepperoni("C:\\Users\\ghazaal\\source\\repos\\mamma maglione 2.6\\assets\\pep-.png", { 420, 500 }),
    onions("C:\\Users\\ghazaal\\source\\repos\\mamma maglione 2.6\\assets\\onion-.png", { 300, 500 })
{
    state = gamestate::HOMEPAGE;

    // Load font
    if (!font.loadFromFile("C:\\Users\\ghazaal\\source\\repos\\mamma maglione 2.6\\assets\\dilla-font\\DillaRegular-0vJYP.ttf")) {
        std::cout << "Error loading font!" << std::endl;
    }

    // Add buttons
    uimanager.addbutton(Button({ 200, 60 }, { 20, 20 }, "Order", font));
    uimanager.addbutton(Button({ 200, 60 }, { 290, 20 }, "Kitchen", font));
    uimanager.addbutton(Button({ 200, 60 }, { 580, 20 }, "Oven", font));

    // Load textures
    orderBgTex.loadFromFile("C:\\Users\\ghazaal\\source\\repos\\mamma maglione 2.6\\assets\\order.png");
    cookingBgTex.loadFromFile("C:\\Users\\ghazaal\\source\\repos\\mamma maglione 2.6\\assets\\cooking station 2.png");
    ovenBgTex.loadFromFile("C:\\Users\\ghazaal\\source\\repos\\mamma maglione 2.6\\assets\\oven.jpeg");
    homeBgTex.loadFromFile("C:\\Users\\ghazaal\\source\\repos\\mamma maglione 2.6\\assets\\outside.png");

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
    audio.start("C:\\Users\\ghazaal\\source\\repos\\mamma maglione 2.6\\assets\\Mambo- Italiano.ogg");

    //intro box
 
    ghazaal.setFont(font);
    ghazaal.setCharacterSize(23);
    ghazaal.setOutlineThickness(1);
    ghazaal.setOutlineColor(Color::Red);
    ghazaal.setFillColor(sf::Color::Black);
    ghazaal.setPosition(350, 630);
    ghazaal.setString("Ghazaal\n25l-2004");
    muaaz.setFont(font);
    muaaz.setCharacterSize(23);
    muaaz.setOutlineThickness(1);
    muaaz.setOutlineColor(sf::Color::Red);
    muaaz.setFillColor(sf::Color::Black);
    muaaz.setPosition(150, 670);
    muaaz.setString("Muaaz\n25l-3087");
    shahbaz.setFont(font);
    shahbaz.setCharacterSize(23);
    shahbaz.setOutlineThickness(1);
    shahbaz.setOutlineColor(sf::Color::Red);
    shahbaz.setFillColor(sf::Color::Black);
    shahbaz.setPosition(590, 670);
    shahbaz.setString("Shahbaz\n25l-0006");

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
        if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
            Vector2f mousepos = window.mapPixelToCoords(Mouse::getPosition(window));
            if (cheese.getSprite().getGlobalBounds().contains(mousepos)) {
                draggedIngredients = &cheese; dragging = true;
            }
            else if (sausage.getSprite().getGlobalBounds().contains(mousepos)) {
                draggedIngredients = &sausage; dragging = true;
            }
            else if (mushrooms.getSprite().getGlobalBounds().contains(mousepos)) {
                draggedIngredients = &mushrooms; dragging = true;
            }
            else if (pepperoni.getSprite().getGlobalBounds().contains(mousepos)) {
                draggedIngredients = &pepperoni;  dragging = true;
            }
            else if (olives.getSprite().getGlobalBounds().contains(mousepos)) {
                draggedIngredients = &olives; dragging = true;
            }
            else if (onions.getSprite().getGlobalBounds().contains(mousepos)) {
                draggedIngredients = &onions; dragging = true;
            }
        }
        if (event.type == sf::Event::MouseButtonReleased &&
            event.mouseButton.button == sf::Mouse::Left) {
            if (dragging && draggedIngredients) {
                sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

                // Place ingredient into pizza matrix
                pizza.placeIngredient(mousePos, draggedIngredients->getSprite());

                // Respawn ingredient back to bowl
                draggedIngredients->respawn();

                draggedIngredients = nullptr;
                dragging = false;
            }
        }
    }
}  

void Game::update() {
    uimanager.update(window);   // hover updates every frame
    if (dragging && draggedIngredients) {
        sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
        draggedIngredients->getSprite().setPosition(mousePos);
    }

}

void Game::render() {
    window.clear();

    if (state == gamestate::HOMEPAGE) {
        window.draw(homeBackground);
        window.draw(ghazaal);
        window.draw(muaaz);
        window.draw(shahbaz);
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
