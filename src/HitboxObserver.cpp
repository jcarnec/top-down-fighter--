
#include "HitboxObserver.h"
#include "Hitbox.h"
#include <iostream>
#include <glm/glm.hpp>

void HitboxObserver::notify(Hitbox* subject) {
   glm::vec2 hitboxPosition = subject->getEntity()->getPosition();
   glm::vec2 hurtboxPosition = entity->getShape().getPosition();

   // if both hitbox and hurtbox are circles
   if (subject->getEntity()->getShape().getType() == "CIRCLE" && entity->getShape().getType() == "CIRCLE") {
       Shape hitboxShape = subject->getEntity()->getShape(); // Store the result in a variable
       Shape hurtboxShape = entity->getShape(); // Store the result in a variable

       float hitboxRadius = dynamic_cast<Circle&>(hitboxShape).getRadius();
       float hurtboxRadius = dynamic_cast<Circle&>(hurtboxShape).getRadius();
       float distance = glm::length(hitboxPosition - hurtboxPosition);
       if (distance < hitboxRadius + hurtboxRadius) {
           std::cout << "Hit!" << std::endl;
       }
   }
   
   
}