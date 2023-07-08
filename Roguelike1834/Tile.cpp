#include "Tile.h"

Tile::Tile(std::string name, bool blocksVision, bool blocksMovement, Tile::MapTile mapTile, Color fg, Color bg)
{
	this->name = name;
	this->blocksMovement = blocksMovement;
	this->blocksVision = blocksVision;
	this->mapTile = mapTile;
	this->fg = fg;
	this->bg = bg;
}

Vector2 Tile::GetActorTile(ActorTile tile)
{
	return Vector2{ 1, 1 };
}

Vector2 Tile::GetMapTile(MapTile tile) {
	return Vector2{ 1,1 };
}

Tile Tile::MakeWall()
{
	return Tile("Wall", true, true, Tile::MapTile::Wall, WHITE, BLACK);
}
