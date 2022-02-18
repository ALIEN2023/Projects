#pragma once
#include <SFML/Graphics.hpp>

const int CELL_SIZE = 120; // размер клетки в пикселях

const int GAMEFIELD_SIZE = 8; // высота и ширина игрового поля

const float LIMIT_FPS = 90.f; // ограничение fps

const sf::Color COLOR_BROWN = { 139, 119, 101 }; // окраска клетки

const int PAWN_SIZE = 9; // количество пешек

const int NOT_SELECTED = 10; // если пешка не выбрана