#pragma once
#include <string>
#include "raylib.h"



class Entity
{
public:
	int x;
	int y;
	Color fg;
	Color bg;
	std::string name;

	Entity(int x, int y, Color fg, Color bg, std::string name);
};

