
#include "HitboxObserver.h"
#include "Hitbox.h"
#include <iostream>
#include <glm/glm.hpp>

void HitboxObserver::notify(Hitbox *subject)
{
    glm::vec2 hitboxPosition = subject->getEntity()->getPosition();
    glm::vec2 hurtboxPosition = entity->getPosition();

    // log
    std::cout << "Hitbox position: " << hitboxPosition.x << ", " << hitboxPosition.y << std::endl;
    std::cout << "Hurtbox position: " << hurtboxPosition.x << ", " << hurtboxPosition.y << std::endl;

    // if both hitbox and hurtbox are circles
    if (subject->getEntity()->getShape().getType() == "SHAPE" && entity->getShape().getType() == "SHAPE")
    {

        // get hitbox and hurtbox shapes
        const Shape& hitboxShape = subject->getEntity()->getShape();
        const Shape& hurtboxShape = entity->getShape();

        float hitboxRadius = hitboxShape.getRadius();
        float hurtboxRadius = hurtboxShape.getRadius();
        
        float distance = glm::length(hitboxPosition - hurtboxPosition);
        std::cout << "Distance: " << distance << std::endl;
        if (distance < hitboxRadius + hurtboxRadius)
        {
            std::cout << "Hit!" << std::endl;
        }
    }
}