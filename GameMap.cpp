#include "GameMap.h"
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>


using namespace std;

GameMap::GameMap(Snake* newSnakeReference)
{
	snakeReference = newSnakeReference;
	LoadMapFromFile();
	SetRandomAppleCell();
}

void GameMap::DrawMap()
{
	system("cls");
	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 80; j++)
		{
			cout << cells[i][j].GetId();
		}
		cout << endl;
	}
}

int GameMap::SetSnakeCell(char snakeIcon)
{
	if (cells[snakeReference->GetY() + snakeReference->GetDirection(1)][snakeReference->GetX() + snakeReference->GetDirection(0)].IsWall())
	{
		return 0;
	}
	else
	{
		if (cells[snakeReference->GetY() + snakeReference->GetDirection(1)][snakeReference->GetX() + snakeReference->GetDirection(0)].IsApple())
		{
			SetRandomAppleCell();
		}

		if (snakeCell != NULL)
		{
			snakeCell->SetId(' ');
		}

		snakeReference->SetPosition(snakeReference->GetX() + snakeReference->GetDirection(0),
									snakeReference->GetY() + snakeReference->GetDirection(1));
		snakeCell = &cells[snakeReference->GetY()][snakeReference->GetX()];
		snakeCell->SetId(snakeIcon);
		return 1;
	}
}

void GameMap::SetRandomAppleCell()
{
	int randX, randY;
	srand(time(NULL));
	do
	{
		AppleCell = &cells[randX = rand() % 28 + 1][randY = rand() % 78 + 1];
	} while (AppleCell == snakeCell);
	AppleCell->SetId('A');
}

void GameMap::LoadMapFromFile()
{
	int row = 0;
	string line;
	ifstream mapFile("Map.txt");

	if (mapFile.is_open())
	{
		while(getline(mapFile, line))
		{
			for (int i = 0; i < line.length(); i++)
			{
				if (line[i] == 'o')
				{
					cells[row][i].SetId(' ');
					snakeReference->SetPosition(i, row);
					snakeCell = &cells[snakeReference->GetY()][snakeReference->GetX()];
					snakeCell->SetId(snakeReference->GetIcon());
					//snakeCell->SetId(line[i]);
				}
				else
				{
					cells[row][i].SetId(line[i]);
				}
			}
			row++;
		}
	}
	else
	{
		cout << "ERROR: MAP FILE COULD NOT BE LOADED" << endl;
	}
}

bool GameMap::GetIsGameOver()
{
	return isGameOver;
}

void GameMap::SetIsGameOver(bool gameOverState)
{
	isGameOver = gameOverState;
}