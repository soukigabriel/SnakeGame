#include "GameMap.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

GameMap::GameMap(Snake* newSnakeReference)
{
	snakeReference = newSnakeReference;
	LoadMapFromFile();
}

void GameMap::DrawMap()
{
	for (int i = 0; i < 45; i++)
	{
		for (int j = 0; j < 150; j++)
		{
			cout << cells[i][j].GetId();
		}
		cout << endl;
	}
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
				}
				cells[row][i].SetId(line[i]);
			}
			row++;
		}
	}
	else
	{
		cout << "ERROR: MAP FILE COULD NOT BE LOADED" << endl;
	}
}