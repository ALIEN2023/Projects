#pragma once
#include "Cell.h"
#include "Constant.h"
#include "BlackPawn.h"
#include "WhitePawn.h"
#include "AI.h"
#include <string>

const int NUMBER_OF_PAWNS = 9; // количество фигур


class Game
{	

private:
	Cell GameField[GAMEFIELD_SIZE][GAMEFIELD_SIZE];
	BlackPawn BlackPawns[NUMBER_OF_PAWNS];
	WhitePawn WhitePawns[NUMBER_OF_PAWNS];
	bool isMove{ false };
	bool s{ false };
	float directionX{ 0.f };
	float directionY{ 0.f };
	int num{ NOT_SELECTED };
	bool step{ true }; // если правда, то ходит игрок
	sf::Text text;
	sf::Font font;
	bool onText{ false };

public:
	sf::Event event;
	sf::RenderWindow window;
	sf::Vector2i pixelPos;
	sf::Vector2f pos;	
	float deltaTime{ 1.f / 60.f };
	sf::Clock clock;
	AI bot;

public:
	Game() {};

	void PlayGame();

	void CreateGameField(sf::RenderWindow& window);

	void Display(sf::RenderWindow& window);

	void CreatePawns(sf::RenderWindow& window);

	void CreateBlackPawns(sf::RenderWindow& window);

	void CreateWhitePawns(sf::RenderWindow& window);

	void MovePawns();

	void MoveBlackPawn();

	void MoveWhitePawn();

	bool GetStep() { return step; }

	void SetStep() { (step) ? step = false : step = true; }

	int GetNum() { return num; }

	void SetNum(const int& i) { num = i; }

	void WinCheck(const bool& b);

	void PrintText(const std::string& t);
};



