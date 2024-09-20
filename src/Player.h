#pragma once
#include <vector>
#include <string>
#include <memory>
#include "BasicPhysicsComponent.h"
#include "StateMachine.h"
#include <glm/glm.hpp>
#include "State.h"
#include <unordered_map>
#include "Entity.h"
#include "StateMachineEntity.h"
#include "InputHandler.h"


class Player : public StateMachineEntity {
public:
    Player(glm::vec2 position, Shape shape, std::shared_ptr<HitboxManager> hm);

    void update() override; // Call to update player state
    void draw() const override; // Call to draw player

    InputHandler& getInputHandler() const { return *inputHandler; }
    void setInputHandler(std::unique_ptr<InputHandler> inputHandler) { this->inputHandler = std::move(inputHandler); }
    void setPhysics(std::unique_ptr<InputHandler> inputHandler) { this->inputHandler = std::move(inputHandler); }
    


private:
    std::unique_ptr<InputHandler> inputHandler;


    

};

