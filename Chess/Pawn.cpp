#include "Pawn.h"

Pawn::Pawn()
{
	texture.loadFromFile("Textures\\black.png");
	sprite.setTexture(texture);
}

void Pawn::draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}

bool Pawn::LegalMove(Cell(&array)[GAMEFIELD_SIZE][GAMEFIELD_SIZE], int i, int j)
{
	if (array[i][j].GetStatusCell() == 0)
	{
		if ((abs(currentCell.x - i) == 1 && abs(currentCell.y - j) == 0) || (abs(currentCell.y - j) == 1 && abs(currentCell.x - i) == 0))
		{
			return true;
		}
	}
	return false;
}