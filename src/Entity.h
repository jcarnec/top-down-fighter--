#pragma once
#include <vector>
#include <string>

#include "StateMachine.h"
#include <glm/glm.hpp>
#include "State.h"
#include <unordered_map>



class Entity {
public:
    Entity(glm::vec2 position, float size) : size(size) {
        getPhysics().setPosition(position);
    }

    virtual ~Entity() = default;

    virtual void update() = 0;
    virtual void draw() const = 0;


    float getSize() const { return size; }
    void setSize(float newRadius) { size = newRadius; }

    // getter and setter for physics
    BasicPhysicsComponent& getPhysics() const { return *physics; }
    void setPhysics(std::unique_ptr<BasicPhysicsComponent> physics) { this->physics = std::move(physics); }

    // getter state machine


protected:
    std::unique_ptr<BasicPhysicsComponent> physics = std::make_unique<BasicPhysicsComponent>(*this);
    float size = 10;
};
