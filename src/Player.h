#pragma once
#include <vector>
#include <string>

#include "StateMachine.h"
#include <glm/glm.hpp>
#include "State.h"
#include <unordered_map>
#include "Entity.h"

class Player : public Entity {
public:
    Player(glm::vec2 position, float size, float moveSpeed);

    void update() override; // Call to update player state
    void draw() const override; // Call to draw player

    void associateInput(std::string commandName);

    StateMachine getStateMachine();


public: 
    // Other public methods or members as needed
    std::unordered_map<std::string, unsigned char> inputMap;


private:
    // Set of input commands
    std::vector<std::string> inputList;
    StateMachine stateMachine;
    

};

