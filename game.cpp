#include "game.h"
#include <iostream>
using namespace sf;
using namespace std;
//constuctor of making a game object, it takes the already existing window as a parameter and sets the gamestate to order screen
Game::Game(RenderWindow& win) : window(win) 
{
	state = (gamestate::HOMEPAGE);

	orderBgTex.loadFromFile("C:\\Users\\ghazaal\\source\\repos\\mamma maglione 2.6\\assets\\oder.jpeg");
	cookingBgTex.loadFromFile("C:\\Users\\ghazaal\\source\\repos\\mamma maglione 2.6\\assets\\cooking station.jpeg");
	ovenBgTex.loadFromFile("C:\\Users\\ghazaal\\source\\repos\\mamma maglione 2.6\\assets\\oven.jpeg");
	homeBgTex.loadFromFile("C:\\Users\\ghazaal\\source\\repos\\mamma maglione 2.6\\assets\\main.jpeg");
	// Assign textures to sprites
	orderBackground.setTexture(orderBgTex);
	cookingBackground.setTexture(cookingBgTex);
	ovenBackground.setTexture(ovenBgTex);
	homeBackground.setTexture(homeBgTex);

	//scale the sprites to fit the window
	auto scaleToWindow = [&](sf::Sprite& sprite, sf::Texture& tex) {
		sf::Vector2u texSize = tex.getSize();
		float scaleX = 800.0f / texSize.x;
		float scaleY = 800.0f / texSize.y;
		sprite.setScale(scaleX, scaleY);
		};

	// Apply scaling
	scaleToWindow(orderBackground, orderBgTex);
	scaleToWindow(cookingBackground, cookingBgTex);
	scaleToWindow(ovenBackground, ovenBgTex);
	scaleToWindow(homeBackground, homeBgTex);
}
//will just run the game
void Game::run()
{
	while (window.isOpen()) 
	{ // main game loop, runs until the window is closed
		handleevents(); // handles events
		update(); // updates the game, we will use that in future for adding more features
		render(); //for drawing
	}
}
void Game::handleevents()
{
	Event event;
	while (window.pollEvent(event)) 
	{ // event loop, runs until there are no more events to process
		if (event.type == Event::Closed) 
		{ // if the event is a request to close the window
			window.close(); // close the window
		}
	}
}
void Game::update()
{
	// we will use this function in future for adding more features
}
void Game::render()
{
	window.clear();
	if (state)
}