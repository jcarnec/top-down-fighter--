
#include "HitboxObserver.h"
#include "Hitbox.h"
#include <iostream>

void HitboxObserver::update(Hitbox* subject) {
    std::cout << "HitboxObserver::update() called" << std::endl;
}