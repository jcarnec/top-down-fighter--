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
    void setVelocity(const glm::vec2& newVelocity) {
        velocity = newVelocity;
    }

    glm::vec2 getVelocity() const {
        return velocity;
    }

    void setAcceleration(const glm::vec2& newAcceleration) {
        acceleration = newAcceleration;
    }

    glm::vec2 getAcceleration() const {
        return acceleration;
    }

    void applyForce(const glm::vec2& force) {
        acceleration += force;
    }

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

    void applyAcceleration() {
        velocity += acceleration;
    }

    void applyMaxSpeed() {
        if (glm::length(velocity) > maxSpeed) {
            velocity = glm::normalize(velocity) * maxSpeed;
        }
    }

    void applyVelocity() {
        position += velocity;
    }

    void applyPhysics() {
        applyAcceleration();
        applyFriction();
        applyMaxSpeed();
        applyVelocity();
    }

};