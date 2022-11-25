#include "GameMap.h"
#include <iostream>

using namespace std;

GameMap::GameMap()
{

}

void GameMap::DrawMap()
{
	for (int i = 0; i < 60; i++)
	{
		for (int j = 0; j < 80; j++)
		{
			cout << cells[i][j].GetId();
		}
		cout << endl;
	}
}