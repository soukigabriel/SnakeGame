#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include <iostream>
#include "GameMap.h"

using namespace std;

int main()
{

	GameMap map;

	map.DrawMap();

	//for (int i = 0; i < 20; i++)
	//{
	//	cout << i << endl;
	//	Sleep(1000);
	//}



	return 0;
}