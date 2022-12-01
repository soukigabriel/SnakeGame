#include "GameMap.h"
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <conio.h>
#include <cctype>


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
			cout << cells[i][j].GetId() << ' ';
		}
		cout << endl;
	}
}

int GameMap::SetSnakeCell(char snakeIcon)
{
	if (cells[snakeReference->GetY() + snakeReference->GetDirection(1)][snakeReference->GetX() + snakeReference->GetDirection(0)].IsWall() || cells[snakeReference->GetY() + snakeReference->GetDirection(1)][snakeReference->GetX() + snakeReference->GetDirection(0)].IsSnake())
	{
		return 0;
	}
	else
	{
		if (cells[snakeReference->GetY() + snakeReference->GetDirection(1)][snakeReference->GetX() + snakeReference->GetDirection(0)].IsApple())
		{
			snakeReference->IncreaseSnakeLenth();
			snakeCell[snakeReference->GetSnakeLength()] = snakeCell[snakeReference->GetSnakeLength() - 1];
			SetRandomAppleCell();
		}

		int snakeLength = snakeReference->GetSnakeLength();
		//if (snakeCell != NULL)
		//{
		//	snakeCell[snakeLength]->SetId(' ');
		//}
		
		snakeCell[snakeLength]->SetId(' ');

		for (int i = snakeLength; i > 0; i--)
		{
			snakeCell[i] = snakeCell[i - 1];
			snakeCell[i]->SetId(snakeIcon);
		}
		snakeReference->SetPosition(snakeReference->GetX() + snakeReference->GetDirection(0),
									snakeReference->GetY() + snakeReference->GetDirection(1));
		snakeCell[0] = &cells[snakeReference->GetY()][snakeReference->GetX()];
		snakeCell[0]->SetId(snakeIcon);
		return 1;
	}
}

void GameMap::SetRandomAppleCell()
{
	int randX, randY;
	srand(time(NULL));
	bool canSetApple = false;

	do
	{
		AppleCell = &cells[randX = rand() % 28 + 1][randY = rand() % 78 + 1];
	} while (EvaluateAppelCell(AppleCell));
	AppleCell->SetId('A');
}

bool GameMap::EvaluateAppelCell(MapCell* theCell)
{
	int snakeLength = snakeReference->GetSnakeLength();
	for (int i = 0; i < snakeLength + 1; i++)
	{
		if (theCell == snakeCell[i]) return true;
	}
	return false;
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
					snakeCell[snakeReference->GetSnakeLength()] = &cells[snakeReference->GetY()][snakeReference->GetX()];
					snakeCell[snakeReference->GetSnakeLength()]->SetId(snakeReference->GetIcon());
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

bool GameMap::DrawMainMenu()
{
	int row = 0;
	string line;
	ifstream mainMenuFile("MainMenu.txt");

	if (mainMenuFile.is_open()) 
	{
		while (getline(mainMenuFile, line))
		{
			cout << line << endl;
		}
		char input = _getch();
		return GetMenuInput(input, 'e');
	}
	else
	{
		cout << "ERROR: MAIN MENU FILE COULD NOT BE LOADED" << endl;
		return false;
	}
}

bool GameMap::GetMenuInput(char key, char charToFalse)
{
	if (key == toupper(charToFalse) || key == tolower(charToFalse))
	{
		return false;
	}
	return true;
}

bool GameMap::GetIsGameOver()
{
	return isGameOver;
}

void GameMap::SetIsGameOver(bool gameOverState)
{
	isGameOver = gameOverState;
}