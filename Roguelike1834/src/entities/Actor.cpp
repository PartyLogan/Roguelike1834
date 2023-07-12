#include "Actor.h"
#include "../actions/Action.h"


Actor::Actor() : Entity(0, 0, WHITE, BLACK, "Entity")
{
	this->tileType = Tile::ActorTile::Player;
}

Actor::Actor(int x, int y, Color fg, Color bg, std::string name, Tile::ActorTile tileType)
	: Entity(x, y, fg, bg,name)
{
	this->tileType = tileType;
}

Action* Actor::GetAction()
{
	Action* action = new Action();
	return action;
}