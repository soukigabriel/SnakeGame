#pragma once
#include "MapCell.h"

#include "Snake.h"
class GameMap
{
public:
	GameMap(Snake* newSnakeReference);
	void DrawMap();
	void LoadMapFromFile();
	MapCell cells[45][150];

	Snake* snakeReference;
	MapCell* snakeCell;
};

