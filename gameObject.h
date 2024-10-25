#pragma once
#include "visitor.h"

class GameObject {
public:
    virtual void accept(Visitor& visitor) = 0;
};
