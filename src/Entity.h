#pragma once
#include <vector>
#include <string>

#include "StateMachine.h"
#include <glm/glm.hpp>
#include "State.h"
#include <unordered_map>

class Entity {
public:
    Entity(glm::vec2 position, float size, float moveSpeed);
    virtual ~Entity() = default;

    virtual void update() = 0;
    virtual void draw() const = 0;

    glm::vec2 getPosition() const;
    void setPosition(glm::vec2 newPosition);

    float getSize() const;
    void setSize(float newRadius);

    float getMoveSpeed() const;
    void setMoveSpeed(float speed);

    // Other getter and setter methods
    void setVelocity(glm::vec2 newVelocity) {
        velocity = newVelocity;
    };
    glm::vec2 getVelocity() const {
        return velocity;
    };

    void setAcceleration(glm::vec2 newAcceleration) {
        acceleration = newAcceleration;
    };
    glm::vec2 getAcceleration() const { 
        return acceleration;
    };

    void setFriction(float newFriction) {
        friction = newFriction;
    };

    float getFriction() const {
        return friction;
    };

    void applyForce(glm::vec2 force) {
        acceleration += force;
    };

    void applyFriction() {
        acceleration -= friction;
    };

    void applyAcceleration() {
        velocity += acceleration;
    };

    void applyVelocity() {
        position += velocity;
    };


    void setMaxSpeed(float newMaxSpeed) {
        maxSpeed = newMaxSpeed;
    };

    float getMaxSpeed() const {
        return maxSpeed;
    };

    void applyMaxSpeed() {
        if (glm::length(velocity) > maxSpeed) {
            velocity = glm::normalize(velocity) * maxSpeed;
        }
    };

    void applyMovement() {
        applyFriction();
        applyAcceleration();
        applyMaxSpeed();
    };

    // getter and setter methods for direction
    void setDirection(glm::vec2 newDirection) {
        direction = newDirection;
    };

    glm::vec2 getDirection() const {
        return direction;
    };





protected:
    glm::vec2 position = glm::vec2(0.0f);
    glm::vec2 velocity = glm::vec2(0.0f);
    glm::vec2 acceleration = glm::vec2(0.0f);
    glm::vec2 direction = glm::vec2(0.0f);
    float friction;
    float size;
    float moveSpeed;
    float maxSpeed = 100.0f;
};
