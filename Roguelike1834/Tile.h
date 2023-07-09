#pragma once
#include "raylib.h"
#include <string>

class Tile
{

public:
	enum ActorTile {
		Player
	};
	enum MapTile {
		Background,
		Blank,
		Floor,
		Wall,
		ForestWall1,
		ForestWall2,
		ForestWall3,
		ForestWall4,
		ForestWall5,
		ForestFloor1,
		ForestFloor2,
		ForestFloor3,
		ForestFloor4,
		ForestFloor5,
	};

	std::string name = "Tile";
	bool blocksVision = false;
	bool blocksMovement = false;
	MapTile mapTile = MapTile::Blank;
	Color bg = BLACK;
	Color fg = WHITE;

	Tile(std::string name, bool blocksVision, bool blocksMovement, MapTile mapTile, Color fg, Color bg);

	static Vector2 GetActorTile(ActorTile tile);
	static Vector2 GetMapTile(MapTile tile);
	static Tile MakeForestWall();
	static Tile MakeForestFloor();

	Tile() = default;
};

