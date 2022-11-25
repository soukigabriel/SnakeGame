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

	map.DrawMap();

	//for (int i = 0; i < 20; i++)
	//{
	//	cout << i << endl;
	//	Sleep(1000);
	//}



	return 0;
}