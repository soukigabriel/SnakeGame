#include "Snake.h"
#include <iostream>
#include <conio.h>

Snake::Snake()
{

}

int Snake::GetX()
{
	return x;
}

int Snake::GetY()
{
	return y;
}

char Snake::GetIcon()
{
	return icon;
}

void Snake::SetPosition(int newX, int newY)
{
	x = newX;
	y = newY;
}

void Snake::GetInput()
{
	//char input = ' ';
	
	if (_kbhit())
	{
		//std::cin >> input;
		switch (_getch())
		{
		case 'w':
			movementDirection[0] = 0;
			movementDirection[1] = -1;
			break;
		case 's':
			movementDirection[0] = 0;
			movementDirection[1] = 1;
			break;
		case 'd':
			movementDirection[0] = 1;
			movementDirection[1] = 0;
			break;
		case 'a':
			movementDirection[0] = -1;
			movementDirection[1] = 0;
			break;
		default:
			break;
		}
	}
}


int Snake::GetDirection(int index)
{
	return movementDirection[index];
}
