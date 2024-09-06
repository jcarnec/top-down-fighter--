#pragma once
#include <vector>
#include <string>

#include "StateMachine.h"
#include <glm/glm.hpp>
#include "State.h"
#include <unordered_map>
#include "HitboxManager.h"



class Entity {
public:
    Entity(glm::vec2 position, float size) : size(size), id(id) {
        getPhysics().setPosition(position);
        // generate unique id of length 10
        id = std::to_string(rand() % 1000000000);
    }

    virtual ~Entity() = default;

    virtual void update() = 0;
    virtual void draw() const = 0;


    float getSize() const { return size; }
    void setSize(float newRadius) { size = newRadius; }

    // getter and setter for physics
    BasicPhysicsComponent& getPhysics() const { return *physics; }
    void setPhysics(std::unique_ptr<BasicPhysicsComponent> physics) { this->physics = std::move(physics); }

    // getter and setter for hitbox manager
    HitboxManager& getHitboxManager() const { return *hitboxManager; }
    void setHitboxManager(std::shared_ptr<HitboxManager> hitboxManager) { this->hitboxManager = hitboxManager; }

    std::string getId() const { return id; }
    void setId(std::string id) { this->id = id; }


protected:
    std::unique_ptr<BasicPhysicsComponent> physics = std::make_unique<BasicPhysicsComponent>(*this);
    // shared_ptr to hitbox manager
    std::shared_ptr<HitboxManager> hitboxManager = std::make_shared<HitboxManager>();
    float size = 10;
    std::string id = "default";
};
