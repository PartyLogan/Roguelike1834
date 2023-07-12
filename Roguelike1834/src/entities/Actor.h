#pragma once
#include "Entity.h"
#include "../maps/Tile.h"
#include "FOV.h"

class Action;

class Actor : public Entity
{
public:
	std::shared_ptr<FOV> fov;
	Tile::ActorTile tileType = Tile::ActorTile::Player;
	Actor();
	Actor(int x, int y, Color fg, Color bg, std::string name, Tile::ActorTile tileType);
	Action* GetAction();
};


