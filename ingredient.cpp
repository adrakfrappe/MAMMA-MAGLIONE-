#include "game.h"
Ingredients::Ingredients(const string& filename, Vector2f pos)
{
	texture.loadFromFile(filename);
	sprite.setTexture(texture);
	sprite.setPosition(pos);
	sprite.setScale(0.25f, 0.25f);// scale down to fit better
	spawnposition = pos;
}
void Ingredients::draw(RenderWindow& window)
{
	window.draw(sprite);
}
Sprite& Ingredients::getSprite()
{
	return sprite;
}
void Ingredients::respawn()
{
	sprite.setPosition(spawnposition);
}