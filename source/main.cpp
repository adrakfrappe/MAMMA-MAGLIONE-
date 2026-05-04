#include "game.h"
using namespace sf;
int main() {
	RenderWindow window(VideoMode({ 800,800 }), "MAMMA MAGLIONE");
	Game game(window);
	game.run();
	return 0;
}

