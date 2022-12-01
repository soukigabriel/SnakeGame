#pragma once
#include "MapCell.h"

#include "Snake.h"
class GameMap
{
public:
	GameMap(Snake* newSnakeReference);
	void DrawMap();
	void DrawHUD();
	void LoadMapFromFile();
	bool DrawMainMenu();
	void DrawGameOver();
	bool GetMenuInput(char key, char charToFalse);
	MapCell cells[30][30];

	int SetSnakeCell(char snakeIcon);
	Snake* snakeReference;
	MapCell* snakeCell[2184];

	MapCell* AppleCell;
	void SetRandomAppleCell();
	bool EvaluateAppelCell(MapCell* theCell);

	bool GetIsGameOver();
	void SetIsGameOver(bool gameOverState);

	int GetSleepTime();
	void DecreaseSleepTime();

protected:
	int sleepTime = 150;
	bool isGameOver = false;
};

