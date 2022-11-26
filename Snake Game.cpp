#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include <iostream>
#include "GameMap.h"
#include "Snake.h"

using namespace std;

int main()
{

	Snake mySnake;
	GameMap map(&mySnake);


	while (!map.GetIsGameOver())
	{
		switch (map.SetSnakeCell(mySnake.GetIcon()))
		{
		case 0:
			map.SetIsGameOver(true);
			continue;
			break;
		case 1:
				map.DrawMap();
				Sleep(100);
				mySnake.GetInput();
			break;
		default:
			break;
		}
	}

	cout << "Game over" << endl;

	return 0;
}