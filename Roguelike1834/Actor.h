#pragma once
#include "Entity.h"
#include "Tile.h"

class Actor : public Entity
{
public:
	Tile::ActorTile tileType;
	Actor();
	Actor(int x, int y, Color fg, Color bg, std::string name, Tile::ActorTile tileType);
};

