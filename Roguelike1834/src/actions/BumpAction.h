#pragma once
#include "Action.h"
#include "../maps/Map.h"
class BumpAction :
    public Action
{
public:
	int deltaX = 0;
	int deltaY = 0;
	std::shared_ptr<Map> map;

	BumpAction(std::shared_ptr<Map> map, int deltaX, int deltaY) : Action()
	{
		this->map = map;
		this->deltaX = deltaX;
		this->deltaY = deltaY;
	}

	ActionResult Perform();

	BumpAction() : Action() {};
};

