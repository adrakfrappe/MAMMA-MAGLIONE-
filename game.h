#pragma once
#include "SFML/Graphics.hpp"
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
public:
	//defining sprites here, will load them in game.cpp
	Texture homeBgTex;
	Texture orderBgTex;
	Texture cookingBgTex;
	Texture ovenBgTex;
	Sprite homeBackground;
	Sprite orderBackground;
	Sprite cookingBackground;
	Sprite ovenBackground;
	Game(RenderWindow& window); // constructor
	void run(); // main game loop
	void handleevents(); // handles events
	void update(); // updates the game, we will use that in future for adding more features
	void render(); //for drawing
};
//game.h#pragma once
