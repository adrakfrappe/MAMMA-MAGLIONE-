#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp" 
#include "UImanager.h"
#include "order.h"
#include "pizza.h"
#include "audio.h"
#include "ingrediens.h"
#include "game.h"
#include <iostream>
#include "button.h"
// your Ingredients class
using namespace std;
using namespace sf;
//class of 6 gamesates
enum class gamestate 
{
	HOMEPAGE,
	ORDER_SCREEN,
	COOKING_SCREEN,
	OVEN_SCREEN,
	SALADBAR_SCREEN,
	Milkshake_bar,
	ResultPizza_SCREEN,
	ResultSalad_SCREEN,
	ResultMilk_Screen
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
	Ingredients tomatoes;
	Ingredients chicken;
	Ingredients onions2;
	Ingredients lettuce;
	Ingredients olives2;
	Ingredients cucumber;//c1
	Ingredients banana;
	Ingredients strawberry;
	Ingredients mangoes;
	Ingredients vanicecream;
	Ingredients chocolateicecream;
	Ingredients tutifrutiicecream;
	Ingredients* draggedIngredients = nullptr;
	Text ghazaal;
	Text muaaz;
	Text shahbaz;
	Text cookingTimeText;

	bool difficultMode = false;
	int difficultRound = 0;
	int firstOrderType = -1;

	int totalScore = 0;
	int Cscore=0;
	Text scoreText;
	Text resultLabel;

	Text saladScoreText;
	Text saladResultLabel;

	Text milkScoreText;
	Text milkResultLabel;
	int cookingTimeSeconds;

	// Clock animation
	Texture clockTextures[21];
	Sprite clockSprite;
	int currentClockFrame = 0;
	bool ovenRunning = false;
	int serveStoppedAt = 0;

	// Clock timing
	sf::Clock ovenClock;
	float clockFrameTimer = 0.f;

	// Result
	Texture resultTex;
	Sprite resultBackground;
	Clock waqt;
	bool dragging = false;
public:
	Order* currentOrder;
	//defining sprites here, will load them in game.cpp
	Texture homeBgTex;
	Texture orderBgTex;
	Texture cookingBgTex;
	Texture ovenBgTex;
	Texture saladbarTex;
	Texture ranchTex;
	Texture mustardTex;
	Texture milkshakeTex;
	Texture blenderTex;
	Sprite blenderbackground;
	Sprite milkshakebackground;
	Sprite mustardbackground;
	Sprite ranchbackground;
	Sprite homeBackground;
	Sprite saladbarbackground;
	Sprite orderBackground;
	Sprite cookingBackground;
	Sprite ovenBackground;
	Game(sf::RenderWindow& window); // constructor
	void run(); // main game loop
	void handleEvents(); // handles events
	void update(); // updates the game, we will use that in future for adding more features
	void render(); //for drawing

};
