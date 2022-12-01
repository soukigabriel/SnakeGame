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
	HWND hWnd = GetConsoleWindow();
	ShowWindow(hWnd, SW_SHOWMAXIMIZED);

	Snake mySnake;
	GameMap map(&mySnake);

	if (map.DrawMainMenu())
	{
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
				Sleep(map.GetSleepTime());
				mySnake.GetInput();
				break;
			default:
				break;
			}
		}
		map.DrawGameOver();
	}


	return 0;
}