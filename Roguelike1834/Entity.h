#pragma once
#include <string>
#include "raylib.h"

class Entity
{
public:
	int x = 0;
	int y = 0;
	Color fg = WHITE;
	Color bg = BLACK;
	std::string name = "Entity";

	Entity(int x, int y, Color fg, Color bg, std::string name);
};

