#pragma once
#include "Tile.h"
#include <vector>
class Map
{
public:
	int width;
	int height;
	std::vector<std::vector<Tile>> tiles;

	Map(int width, int height);
};

