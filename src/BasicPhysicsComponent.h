#pragma once
#include <glm/glm.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include "PhysicsComponent.h"

class BasicPhysicsComponent : public PhysicsComponent {
public:
    BasicPhysicsComponent(Entity& owner) : PhysicsComponent(owner) {};

    // Internal
    void setVelocity(const glm::vec2& newVelocity) { velocity = newVelocity; }
    glm::vec2 getVelocity() const { return velocity; }
    void setAcceleration(const glm::vec2& newAcceleration) { acceleration = newAcceleration; }
    glm::vec2 getAcceleration() const { return acceleration; }

    void applyForce(const glm::vec2& force) { acceleration += force; }
    void applyVelocity() { position += velocity; }
    void applyAcceleration() { velocity += acceleration; }
    void applyFriction() {
        if (glm::length(velocity) > 0.0f) {
            glm::vec2 frictionDirection = -glm::normalize(velocity);
            glm::vec2 frictionVector = frictionDirection * friction;
            if (glm::length(frictionVector) > glm::length(velocity)) {
                velocity = glm::vec2(0.0f);
            } else {
                velocity += frictionVector;
            }
        }
    }
    void applyMaxSpeed() { if (glm::length(velocity) > maxSpeed) {
         velocity = glm::normalize(velocity) * maxSpeed;
        }
    }


    // External
    void setEVelocity(const glm::vec2& newEVelocity) { eVelocity = newEVelocity; }
    glm::vec2 getEVelocity() const { return eVelocity; }
    void setEAcceleration(const glm::vec2& newEAcceleration) { eAcceleration = newEAcceleration; }
    glm::vec2 getEAcceleration() const { return eAcceleration; }

    void applyEForce(const glm::vec2& eForce) { eAcceleration += eForce; }
    void applyEVelocity() { position += eVelocity; }
    void applyEAcceleration() { eVelocity += eAcceleration; }
    void applyEFriction() {
        // if(glm::length(eVelocity) > 0.0f) {
            // std::cout << "Applying external friction" << std::endl;
            // std::cout << "eVelocity: " << eVelocity.x << ", " << eVelocity.y << std::endl;
        // }
        if (glm::length(eVelocity) > 0.0f) {
            glm::vec2 eFrictionDirection = -glm::normalize(eVelocity);
            // std::cout << "eFrictionDirection: " << eFrictionDirection.x << ", " << eFrictionDirection.y << std::endl;
            glm::vec2 eFrictionVector = eFrictionDirection * eFriction;
            // std::cout << "eFrictionVector: " << eFrictionVector.x << ", " << eFrictionVector.y << std::endl;
            if (glm::length(eFrictionVector) > glm::length(eVelocity)) {
                eVelocity = glm::vec2(0.0f);
            } else {
                eVelocity += eFrictionVector;
            }
        }

    }
    void applyEMaxSpeed() { if (glm::length(eVelocity) > eMaxSpeed) {
         eVelocity = glm::normalize(eVelocity) * eMaxSpeed;
        }
    }

    void applyPhysics() {
        // Internal

        applyAcceleration();
        applyFriction();
        applyMaxSpeed();
        applyVelocity();

        // External
        applyEAcceleration();
        applyEFriction();
        applyEMaxSpeed();
        applyEVelocity();
        applyEVelocity();

    }

};