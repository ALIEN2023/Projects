#pragma once
#include "Cell.h"

class Pawn
{

private:
	sf::Vector2f moveVector;
	sf::Vector2f currentPosition;
	sf::Vector2i currentCell;

protected:
	sf::Texture texture;
	int colorPawn;

public:
	sf::Sprite sprite;

public:
	Pawn();

	sf::Vector2f GetVector() { return moveVector; }

	void SetVector(const sf::Vector2f& v) { moveVector = v; }

	sf::Vector2f GetCurrentPosition() { return currentPosition; }

	void SetCurrentPosition(const sf::Vector2f& v) { currentPosition = v; }

	sf::Vector2i GetCurrentCell() { return currentCell; }

	void SetCurrentCell(const sf::Vector2i& v) { currentCell = v; }

	void draw(sf::RenderWindow& window);

	int GetStatus() { return colorPawn; }

	bool LegalMove(Cell(&array)[GAMEFIELD_SIZE][GAMEFIELD_SIZE], int i, int j);
};