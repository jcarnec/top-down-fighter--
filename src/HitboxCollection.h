
# pragma once

#include <vector>
#include <memory>
#include "Hitbox.h"

class HitboxCollection {

// constructor 
public:
    HitboxCollection() {}

public:
    // collection of hitboxes
    std::vector<std::shared_ptr<Hitbox>> hitboxes;
};