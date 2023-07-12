#include "BumpAction.h"
#include "ActionResult.h"
#include "WalkAction.h"

ActionResult BumpAction::Perform()
{
	if (owner == nullptr) {
		return ActionResult::Failure();
	}

	int tileX = owner.get()->x + deltaX;
	int tileY = owner.get()->y + deltaY;

	if (map.get()->IsBlocked(tileX, tileY)) {
		return ActionResult::Failure();
	}
	else {
		WalkAction* alt = new WalkAction(deltaX, deltaY);
		alt->SetOwner(owner);
		return ActionResult::Alternative(alt);
	}
}
