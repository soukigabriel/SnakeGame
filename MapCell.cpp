#include "MapCell.h"

MapCell::MapCell()
{
	id = 'A';
}

char MapCell::GetId() {
	return id;
}

void MapCell::SetId(char newID)
{
	id = newID;
}

bool MapCell::IsWall()
{
	return id == 'X' ? true : false;
}

bool MapCell::IsApple()
{
	return id == 'A' ? true : false;
}