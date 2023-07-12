#include "WalkAction.h"
#include "ActionResult.h"

ActionResult WalkAction::Perform()
{
	if (owner == nullptr) {
		return ActionResult::Failure();
	}

	owner.get()->x += deltaX;
	owner.get()->y += deltaY;
	return ActionResult::Success();
}
