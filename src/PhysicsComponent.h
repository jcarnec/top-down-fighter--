#pragma once
#include <glm/glm.hpp>
#include <iostream>
#include <vector>


class Entity;

class PhysicsComponent {
public:



    PhysicsComponent(Entity& owner) : owner(owner) {};
    virtual void applyForce(const glm::vec2& force) = 0;
    virtual void applyFriction() = 0;
    virtual void applyAcceleration() = 0;
    virtual void applyMaxSpeed() = 0;
    virtual void applyVelocity() = 0;
    virtual void applyPhysics() = 0;

    // Getter and setter methods for other properties...
    virtual void setVelocity(const glm::vec2& newVelocity) { velocity = newVelocity;}
    virtual glm::vec2 getVelocity() const { return velocity; }
    virtual void setAcceleration(const glm::vec2& newAcceleration) { acceleration = newAcceleration; }
    virtual glm::vec2 getAcceleration() const { return acceleration;}
    virtual void setPosition(const glm::vec2& newPosition) { position = newPosition; }
    virtual glm::vec2 getPosition() const {
         return position;
    }
    virtual void setFriction(float newFriction) { friction = newFriction;}
    virtual float getFriction() const { return friction; }
    virtual void setMaxSpeed(float newMaxSpeed) { maxSpeed = newMaxSpeed;}
    virtual float getMaxSpeed() const { return maxSpeed; }
    virtual void setMoveAcceleration(float newMoveSpeed) { moveAcceleration = newMoveSpeed; }
    virtual float getMoveAcceleration() const { return moveAcceleration; }
    virtual void setDirection(const glm::vec2& newDirection) { direction = newDirection; }
    virtual glm::vec2 getDirection() const { return direction; }


protected:
    glm::vec2 velocity = glm::vec2(0.0f);
    glm::vec2 acceleration = glm::vec2(0.0f);
    glm::vec2 position = glm::vec2(0.0f);
    glm::vec2 direction = glm::vec2(0.0f);
    float friction = 0.2f;
    float maxSpeed = 10;
    float moveAcceleration = 2;
    Entity& owner;

    // Other physics-related methods...
};