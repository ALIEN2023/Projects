#include "BlackPawn.h"

BlackPawn::BlackPawn()
{
	texture.loadFromFile("Textures\\black.png");
	sprite.setTexture(texture);
	colorPawn = 2;
}
