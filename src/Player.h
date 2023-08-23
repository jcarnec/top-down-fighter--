#pragma once
#include <vector>
#include <string>

#include "StateMachine.h"
#include <glm/glm.hpp>
#include "State.h"
#include <unordered_map>
#include "Entity.h"
#include "StateMachineEntity.h"

class Player : public StateMachineEntity {
public:
    Player(glm::vec2 position, float size, float moveSpeed);

    void update() override; // Call to update player state
    void draw() const override; // Call to draw player

    void associateInput(std::string commandName);

    // getter and setter input list
    std::vector<std::string> getInputList();
    void setInputList(std::vector<std::string> inputList);

    // getter state machine
    StateMachine& getStateMachine();

    // clear input list
    void clearInputList();

public: 
    // Other public methods or members as needed
    std::unordered_map<std::string, unsigned char> inputMap;


private:
    // Set of input commands
    std::vector<std::string> inputList;
    

};

