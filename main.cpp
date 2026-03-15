#include "SFML/Graphics.hpp"
using namespace sf;
#include "game.h"
int main() {
	RenderWindow window(VideoMode({ 800,800 }), "MAMMA MAGLIONE");
	Game game(window);
	game.run();
	return 0;
}

//main.cpp