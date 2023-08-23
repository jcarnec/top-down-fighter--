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

    virtual void update();
    virtual void draw() const;

    glm::vec2 getPosition() const;
    void setPosition(glm::vec2 newPosition);

    // Other getter and setter methods

private:
    glm::vec2 position;
    float size;
    float moveSpeed;
};
