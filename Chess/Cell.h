#pragma once
#include "Constant.h"

class Cell
{

private:
	sf::Texture texture;
	sf::Vector2f position;
	int statusCell{ 0 };

public:
	sf::Sprite sprite;

public:
	Cell();

	sf::Vector2f GetPositionCell() const { return position; }

	void SetPositionCell(const sf::Vector2f& vector) { position = vector; }

	int GetStatusCell() const { return statusCell; }

	void SetStatusCell(const int& status = 0) { statusCell = status; }

	void SetBrown();

	void draw(sf::RenderWindow& window);

	sf::Sprite GetSprite() const { return sprite; }
};