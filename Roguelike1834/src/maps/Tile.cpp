#include "Tile.h"
#include "../Palette.h"

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
	switch (tile) {
	case ActorTile::Player:
		return Vector2{ 25, 0 };
	default:
		return Vector2{ 0, 0 };
	}

}

Vector2 Tile::GetMapTile(MapTile tile) {
	switch (tile) {
	// Default tiles
	case MapTile::Background:
		return Vector2{ 8, 5 };
	case MapTile::Wall:
		return Vector2{ 8, 5 };
	case MapTile::Floor:
		return Vector2{ 8, 5 };
	//Forest walls
	case MapTile::ForestWall1:
		return Vector2{ 3, 2 };
	case MapTile::ForestWall2:
		return Vector2{ 3, 1 };
	case MapTile::ForestWall3:
		return Vector2{ 2, 1 };
	case MapTile::ForestWall4:
		return Vector2{ 4, 2 };
	case MapTile::ForestWall5:
		return Vector2{ 1, 1 };
	// Forest Floors
	case MapTile::ForestFloor1:
		return Vector2{ 5, 0 };
	case MapTile::ForestFloor2:
		return Vector2{ 1, 0 };
	case MapTile::ForestFloor3:
		return Vector2{ 7, 0 };
	case MapTile::ForestFloor4:
		return Vector2{ 6, 0 };
	case MapTile::ForestFloor5:
		return Vector2{ 0, 2 };
	// Blank
	case MapTile::Blank:
		return Vector2{ 0, 0 };
	default:
		return Vector2{ 0 ,0 };
	}
}

std::shared_ptr<Tile> Tile::MakeForestWall()
{
	int rng = GetRandomValue(0, 4);
	Tile::MapTile type = MapTile::Wall;

	switch (rng) {
	case 0:
		type = MapTile::ForestWall1;
		break;
	case 1:
		type = MapTile::ForestWall2;
		break;
	case 2:
		type = MapTile::ForestWall3;
		break;
	case 3:
		type = MapTile::ForestWall4;
		break;
	case 4:
		type = MapTile::ForestWall5;
		break;
	}

	return std::make_shared<Tile>("Forest Wall", true, true, type, P_TREES, P_DIRT);
}

std::shared_ptr<Tile> Tile::MakeForestFloor()
{
	int rng = GetRandomValue(0, 5);
	Tile::MapTile type = MapTile::Floor;

	switch (rng) {
	case 0:
		type = MapTile::ForestFloor1;
		break;
	case 1:
		type = MapTile::ForestFloor2;
		break;
	case 2:
		type = MapTile::ForestFloor3;
		break;
	case 3:
		type = MapTile::ForestFloor4;
		break;
	case 4:
		type = MapTile::ForestFloor5;
		break;
	case 5:
		type = MapTile::Blank;
		break;
	}
	return std::make_shared<Tile>("Forest Floor", false, false, type, P_GRASS, P_DIRT);
}