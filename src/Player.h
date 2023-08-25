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

class Player : public StateMachineEntity {
public:
    Player(glm::vec2 position, float size);

    void update() override; // Call to update player state
    void draw() const override; // Call to draw player

    void associateInput(std::string commandName);

    // getter and setter input list
    std::vector<std::string> getInputList() { return inputList;}
    void setInputList(std::vector<std::string> inputList) { this->inputList = inputList; }

    // clear input list
    void clearInputList();

public:
    std::unordered_map<std::string, unsigned char> inputMap;


private:
    // Set of input commands
    std::vector<std::string> inputList;

    

};

