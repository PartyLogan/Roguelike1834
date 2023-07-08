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
		Floor,
		Wall
	};

	std::string name;
	bool blocksVision;
	bool blocksMovement;
	MapTile mapTile;
	Color bg;
	Color fg;

	Tile(std::string name, bool blocksVision, bool blocksMovement, MapTile mapTile, Color fg, Color bg);

	static Vector2 GetActorTile(ActorTile tile);
	static Vector2 GetMapTile(MapTile tile);
	static Tile MakeWall();

	Tile() = default;
};

