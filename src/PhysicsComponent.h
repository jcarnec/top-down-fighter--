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

    virtual void applyEForce(const glm::vec2& force) = 0;
    virtual void applyEFriction() = 0;
    virtual void applyEAcceleration() = 0;
    virtual void applyEMaxSpeed() = 0;
    virtual void applyEVelocity() = 0;

    // Getter and setter methods for other properties...
    virtual void setVelocity(const glm::vec2& newVelocity) { velocity = newVelocity;}
    virtual glm::vec2 getVelocity() const { return velocity; }
    virtual void setAcceleration(const glm::vec2& newAcceleration) { acceleration = newAcceleration; }
    virtual glm::vec2 getAcceleration() const { return acceleration;}
    virtual void setPosition(const glm::vec2& newPosition) { position = newPosition; }
    virtual glm::vec2 getPosition() const { return position; }
    virtual void setFriction(float newFriction) { friction = newFriction;}
    virtual float getFriction() const { return friction; }
    virtual void setMaxSpeed(float newMaxSpeed) { maxSpeed = newMaxSpeed;}
    virtual float getMaxSpeed() const { return maxSpeed; }
    virtual void setMoveForce(float newMoveSpeed) { moveForce = newMoveSpeed; }
    virtual float getMoveForce() const { return moveForce; }
    virtual void setOrientation(const glm::vec2& newOrientation) { orientation = newOrientation; }
    virtual glm::vec2 getOrientation() const { return orientation; }

    virtual void setEVelocity(const glm::vec2& newVelocity) { velocity = newVelocity;}
    virtual glm::vec2 getEVelocity() const { return velocity; }
    virtual void setEAcceleration(const glm::vec2& newAcceleration) { acceleration = newAcceleration; }
    virtual glm::vec2 getEAcceleration() const { return acceleration;}
    virtual void setEFriction(float newFriction) { friction = newFriction;}
    virtual float getEFriction() const { return friction; }
    virtual void setEMaxSpeed(float newMaxSpeed) { maxSpeed = newMaxSpeed;}
    virtual float getEMaxSpeed() const { return maxSpeed; }
    virtual void setEMoveForce(float newMoveSpeed) { moveForce = newMoveSpeed; }
    virtual float getEMoveForce() const { return moveForce; }

protected:
    glm::vec2 velocity = glm::vec2(0.0f);
    glm::vec2 acceleration = glm::vec2(0.0f);
    glm::vec2 position = glm::vec2(0.0f);
    glm::vec2 orientation = glm::vec2(0.0f);
    float friction = 0.2f;
    float maxSpeed = 10;
    float moveForce = 1.5;


    glm::vec2 eVelocity = glm::vec2(0.0f);
    glm::vec2 eAcceleration = glm::vec2(0.0f);
    glm::vec2 eDirection = glm::vec2(0.0f);
    float eFriction = 0.2f;
    float eMaxSpeed = 10;
    float eMoveForce = 2;
    Entity& owner;

    // Other physics-related methods...
};