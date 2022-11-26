#pragma once
class Snake
{
public:

	Snake();
	int GetX();
	int GetY();
	char GetIcon();
	void SetPosition(int newX, int newY);
	void GetInput();
	int GetDirection(int index);

protected:
	int x, y;
	char icon = 'o';
	int movementDirection[2] = { 1 , 0 };
};

