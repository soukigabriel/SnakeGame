#include "Snake.h"
#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

Snake::Snake()
{
	snakeLength = 0;
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
	char input = ' ';

	//if (_kbhit())
	//{
	//	input = _getch();
	//	switch (input)
	//	{
	//	case 'w':
	//		if (movementDirection[1] == 1) break;
	//		movementDirection[0] = 0;
	//		movementDirection[1] = -1;
	//		break;
	//	case 's':
	//		if (movementDirection[1] == -1) break;
	//		movementDirection[0] = 0;
	//		movementDirection[1] = 1;
	//		break;
	//	case 'd':
	//		if (movementDirection[0] == -1) break;
	//		movementDirection[0] = 1;
	//		movementDirection[1] = 0;
	//		break;
	//	case 'a':
	//		if (movementDirection[0] == 1) break;
	//		movementDirection[0] = -1;
	//		movementDirection[1] = 0;
	//		break;
	//	default:
	//		break;
	//	}
	//}

	while (_kbhit())
	{
		input = _getch();
	}
	switch (input)
	{
		case 'w':
			if (movementDirection[1] == 1) break;
			movementDirection[0] = 0;
			movementDirection[1] = -1;
			break;
		case 's':
			if (movementDirection[1] == -1) break;
			movementDirection[0] = 0;
			movementDirection[1] = 1;
			break;
		case 'd':
			if (movementDirection[0] == -1) break;
			movementDirection[0] = 1;
			movementDirection[1] = 0;
			break;
		case 'a':
			if (movementDirection[0] == 1) break;
			movementDirection[0] = -1;
			movementDirection[1] = 0;
			break;
		default:
			break;
	}
}


int Snake::GetDirection(int index)
{
	return movementDirection[index];
}

int Snake::GetSnakeLength()
{
	return snakeLength;
}

void Snake::IncreaseSnakeLenth()
{
	snakeLength++;
}

int Snake::GetScore() {
	return score;
}

void Snake::IncreaseScore()
{
	score++;
}
