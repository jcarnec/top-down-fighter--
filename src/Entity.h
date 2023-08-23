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

protected:
    glm::vec2 position;
    float size;
    float moveSpeed;
};
