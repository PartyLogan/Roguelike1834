#pragma once
#include "Tile.h"
#include <vector>
class Map
{
public:
	int width = 80;
	int height = 50;
	std::vector<std::vector<Tile>> tiles;

	Map(int width, int height);
};

