#pragma once
#include <vector>
#include <string>
#include <memory>
#include "BasicPhysicsComponent.h"
#include <glm/glm.hpp>
#include "State.h"
#include <unordered_map>
#include "Entity.h"
#include "InputHandler.h"
#include "HitboxManager.h"


class Player : public Entity {
public:
    Player(glm::vec2 position, Shape shape, std::shared_ptr<HitboxManager> hm);

    void update(); 
    void draw(); 

    InputHandler& getInputHandler() const { return *inputHandler; }
    void setInputHandler(std::unique_ptr<InputHandler> inputHandler) { this->inputHandler = std::move(inputHandler); }
    void setPhysics(std::unique_ptr<InputHandler> inputHandler) { this->inputHandler = std::move(inputHandler); }
    


private:
    std::unique_ptr<InputHandler> inputHandler;


    

};

