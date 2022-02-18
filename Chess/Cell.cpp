#include "Cell.h"
#include "Constant.h"

Cell::Cell()
{
	texture.loadFromFile("Textures\\cell-n.png");
	sprite.setTexture(texture);
}

void Cell::SetBrown()
{
	sprite.setColor(COLOR_BROWN);
}

void Cell::draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}
