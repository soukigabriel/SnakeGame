#pragma once
#include "MapCell.h"

#include "Snake.h"
class GameMap
{
public:
	GameMap(Snake* newSnakeReference);
	void DrawMap();
	void LoadMapFromFile();
	MapCell cells[30][80];

	void SetSnakeCell(char snakeIcon);
	Snake* snakeReference;
	MapCell* snakeCell;

	bool GetIsGameOver();
	void SetIsGameOver(bool gameOverState);

protected:
	bool isGameOver = false;
};

