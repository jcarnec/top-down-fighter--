
#pragma once
#include <vector>
#include <string>

#include "StateMachine.h"
#include <glm/glm.hpp>
#include "State.h"
#include <unordered_map>
#include "Entity.h"

class StateMachineEntity : public Entity {
public:
    StateMachineEntity(glm::vec2 position, float size) : Entity(position, size) {};

    virtual void update() = 0; // Call to update player state
    virtual void draw() const = 0;

    StateMachine& getStateMachine() { return stateMachine; };

protected:
    StateMachine stateMachine;
    

};

