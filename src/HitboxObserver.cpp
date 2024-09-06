
#include "HitboxObserver.h"
#include "Hitbox.h"
#include <iostream>

void HitboxObserver::notify(Hitbox* subject) {
   std::cout << "HitboxObserver::update() called" << std::endl;
   std::cout << "Hitbox position: " << subject->getPosition().x << ", " << subject->getPosition().y << std::endl;
   // Check if the hitbox is colliding with this observer
   
}