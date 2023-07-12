#pragma once
#include "Entity.h"
#include "../maps/Tile.h"

class Action;

class Actor : public Entity
{
public:
	Tile::ActorTile tileType = Tile::ActorTile::Player;
	Actor();
	Actor(int x, int y, Color fg, Color bg, std::string name, Tile::ActorTile tileType);
	Action* GetAction();
};


