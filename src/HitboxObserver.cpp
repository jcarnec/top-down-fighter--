
#include "HitboxObserver.h"
#include "Hitbox.h"
#include <iostream>
#include "BasicPhysicsComponent.h"
#include <glm/glm.hpp>



void HitboxObserver::notify(Hitbox *subject)
{
    glm::vec2 hitboxPosition = subject->getOwner()->getPosition();
    glm::vec2 hurtboxPosition = owner->getPosition();

    // if both hitbox and hurtbox are circles
    if (subject->getOwner()->getShape().getType() == "SHAPE")
    {

        // get hitbox and hurtbox shapes
        const Shape &hitboxShape = subject->getOwner()->getShape();
        const Shape &hurtboxShape = owner->getShape();

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

    BasicPhysicsComponent* selfPhysicsComponent = owner->getComponent<BasicPhysicsComponent>();

    if(selfPhysicsComponent != nullptr) {


        // calculate resulting vector


    } else {
        std::cout << "NO PHYSICS IMPLEMENTED" << std::endl; 
    }

    hb->onHitting(*this);
}