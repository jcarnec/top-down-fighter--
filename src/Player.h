#pragma once
#include <vector>
#include <string>

#include "StateMachine.h"
#include <glm/glm.hpp>
#include "State.h"
#include <unordered_map>

class Player {
public:
    Player(glm::vec2 position, float size, float moveSpeed);

    void update(); // Call to update player state
    void draw() const;

    // Getter and setter methods for attributes
    glm::vec2 getPosition() const;
    void setPosition(glm::vec2 newPosition);

    float getSize() const;
    void setSize(float newSize);

    float getMoveSpeed() const;
    void setMoveSpeed(float speed);

    void associateInput(std::string commandName);

    StateMachine getStateMachine();


public: 
    // Other public methods or members as needed
    std::unordered_map<std::string, unsigned char> inputMap;


private:
    glm::vec2 position;
    float size;
    float moveSpeed;
    // Set of input commands
    std::vector<std::string> inputList;
    StateMachine stateMachine;
    

};

