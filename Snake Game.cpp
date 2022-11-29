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
	//char c = ' ';
	//while (c != 'x')
	//{
	//	cin >> c;
	//	cout << c << endl;
	//}

	//for (int i = 0; i < 256; i++)
	//{
	//	char c = i;
	//	cout << i << ": " << c << endl;
	//}

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