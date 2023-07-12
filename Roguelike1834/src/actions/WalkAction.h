#pragma once
#include "Action.h"

class WalkAction : public Action
{
public:
	int deltaX = 0;
	int deltaY = 0;

	WalkAction(int deltaX, int deltaY) : Action()
	{
		this->deltaX = deltaX;
		this->deltaY = deltaY;
	}

	ActionResult Perform();

	WalkAction() : Action() {};
};

