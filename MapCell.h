#pragma once
class MapCell
{
public:
	MapCell();
	char GetId();
	void SetId(char newID);
	bool IsWall();
	bool IsApple();

protected:
	char id;
};

