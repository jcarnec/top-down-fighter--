
#include "HitboxObserver.h"
#include "Hitbox.h"
#include <iostream>
#include <glm/glm.hpp>



void HitboxObserver::notify(Hitbox *subject)
{
    glm::vec2 hitboxPosition = subject->getEntity()->getPosition();
    glm::vec2 hurtboxPosition = entity->getPosition();

    // if both hitbox and hurtbox are circles
    if (subject->getEntity()->getShape().getType() == "SHAPE")
    {

        // get hitbox and hurtbox shapes
        const Shape &hitboxShape = subject->getEntity()->getShape();
        const Shape &hurtboxShape = entity->getShape();

        float hitboxRadius = hitboxShape.getRadius();
        float hurtboxRadius = hurtboxShape.getRadius();

        float distance = glm::length(hitboxPosition - hurtboxPosition);
        if (distance < hitboxRadius + hurtboxRadius)
        {
            onGettingHit(subject);
        }
    }
}

void HitboxObserver::onGettingHit(Hitbox *hb) {
    std::cout << "I was Hit!" << std::endl;
    hb->onHitting(*this);
}