#pragma once
#include "MapCell.h"

class GameMap
{
public:
	GameMap();
	void DrawMap();
	MapCell cells[60][80];
};

