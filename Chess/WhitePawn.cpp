#include "WhitePawn.h"

WhitePawn::WhitePawn()
{
	texture.loadFromFile("Textures\\white.png");
	sprite.setTexture(texture);
	colorPawn = 1;
}
