#include "Entity.h"

Entity::Entity(int x, int y, Color fg, Color bg, std::string name)
{
	this->x = x;
	this->y = y;
	this->fg = fg;
	this->bg = bg;
	this->name = name;
}
