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