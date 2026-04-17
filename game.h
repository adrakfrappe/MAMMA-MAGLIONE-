#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp" 
#include "UImanager.h"
#include "order.h"
#include "pizza.h"
#include "audio.h"
#include "ingrediens.h"
using namespace sf;

//class of 3 gamesates
enum class gamestate {
	HOMEPAGE,
	ORDER_SCREEN,
	COOKING_SCREEN,
	OVEN_SCREEN,
};

//class of Game controlling all the major functions
class Game
{
	RenderWindow& window; // referes to the already existing window created in main
	gamestate state; // current gamestate
	Font font; // font for text, will load it in game.cpp
	UImanager uimanager;
	Pizza pizza; // pizza object for cooking screen
	AudioManager audio; // background music
	Ingredients cheese;
	Ingredients olives;
	Ingredients mushrooms;
	Ingredients onions;
	Ingredients pepperoni;
	Ingredients sausage;
public:
	Order* currentOrder;
	//defining sprites here, will load them in game.cpp
	Texture homeBgTex;
	Texture orderBgTex;
	Texture cookingBgTex;
	Texture ovenBgTex;
	Sprite homeBackground;
	Sprite orderBackground;
	Sprite cookingBackground;
	Sprite ovenBackground;
	Game(sf::RenderWindow& window); // constructor
	void run(); // main game loop
	void handleEvents(); // handles events
	void update(); // updates the game, we will use that in future for adding more features
	void render(); //for drawing

};
