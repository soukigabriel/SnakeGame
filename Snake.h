#pragma once
class Snake
{
public:

	Snake();
	int GetX();
	int GetY();
	char GetIcon();
	void SetPosition(int newX, int newY);

protected:
	int x, y;
	char icon;
};

