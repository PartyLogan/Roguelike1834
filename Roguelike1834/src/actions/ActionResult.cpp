#include "ActionResult.h"

ActionResult::ActionResult(bool success, Action* alt)
{
	this->succeeded = success;
	this->alternative = alt;
}
