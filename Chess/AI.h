#pragma once
#include "Constant.h"
#include "BlackPawn.h"
#include "Cell.h"

class AI
{

private:
	int numberPawn{ 0 };
	int cellX{ 1 };
	int cellY{ 1 };
	bool lastCell{ false };
	bool firstCondition{ false };
	bool secondCondition{ false };

public:
	AI() {}

	int GetNumberPawn() { return numberPawn; }

	bool MoveBlackPawn(Cell (&field)[GAMEFIELD_SIZE][GAMEFIELD_SIZE], BlackPawn (&pawns)[PAWN_SIZE]);

	bool DirectionPawn(Cell(&field)[GAMEFIELD_SIZE][GAMEFIELD_SIZE], BlackPawn(&pawns)[PAWN_SIZE]);

	bool MoveDown(Cell(&field)[GAMEFIELD_SIZE][GAMEFIELD_SIZE], BlackPawn(&pawns)[PAWN_SIZE]);

	bool MoveRight(Cell(&field)[GAMEFIELD_SIZE][GAMEFIELD_SIZE], BlackPawn(&pawns)[PAWN_SIZE]);

	bool MoveUp(Cell(&field)[GAMEFIELD_SIZE][GAMEFIELD_SIZE], BlackPawn(&pawns)[PAWN_SIZE]);

	bool MoveLeft(Cell(&field)[GAMEFIELD_SIZE][GAMEFIELD_SIZE], BlackPawn(&pawns)[PAWN_SIZE]);

	int GetCellX() { return cellX; }

	int GetCellY() { return cellY; }

	bool GetLastCell() { return lastCell; }
};