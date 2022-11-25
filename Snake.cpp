#include "Snake.h"

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
