#include "Map.h"

Map::Map(int width, int height)
{
	this->width = width;
	this->height = height;
	tiles = std::vector<std::vector<Tile>>();
	tiles.resize(width, std::vector<Tile>(height));

	for (int x = 0; x < width; x++) {
		for (int y = 0; y < height; y++) {
			tiles[x][y] = Tile::MakeForestWall();
		}
	}
}
