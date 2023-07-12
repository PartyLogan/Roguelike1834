#pragma once
#include<memory>
#include "../entities/Actor.h"

class ActionResult;

class Action
{
public:
	std::shared_ptr<Actor> owner;

	Action();
	virtual ActionResult Perform();

	void SetOwner(std::shared_ptr<Actor> owner) {
		this->owner = owner;
	}
};



