#pragma once
#include "Action.h"
#include<memory>

class ActionResult
{
public:
    ActionResult(bool success, Action* alt);

    bool succeeded = false;
    Action* alternative;


    static inline ActionResult Success() {
        return { true, nullptr };
    }

    static inline ActionResult Failure() {
        return { false, nullptr };
    }

    static inline ActionResult Alternative(Action* alt) {
        return { false, alt };
    }

};
