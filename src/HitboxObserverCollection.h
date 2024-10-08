
# pragma once

#include <vector>
#include <memory>
#include "HitboxObserver.h"

class HitboxObserverCollection {

// constructor 
public:
    HitboxObserverCollection() {}

public:
    // collection of hitboxes
    std::vector<std::shared_ptr<HitboxObserver>> hitboxObservers;
};