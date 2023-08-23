#include "Player.h"
#include <GL/glut.h>
#include <cmath>
// #include <memory> // Make sure to include this header for std::make_unique


// Player constructor...
Player::Player(glm::vec2 position, float size, float moveSpeed)
    : StateMachineEntity(position, size, moveSpeed) {
   // Associate commands with keys in the inputMap

        inputMap["UP"] = 'w';
        inputMap["LEFT"] = 'a';
        inputMap["DOWN"] = 's';
        inputMap["RIGHT"] = 'd';


        // Register states with the state machine
        stateMachine.registerState("STANDING", std::make_unique<StandingState>(this, "STANDING"));
        stateMachine.registerState("MOVING", std::make_unique<MovingState>(this, "MOVING"));
        
        // Set the current player for the state machine
        stateMachine.setCurrentPlayer(this);
        
        // Initial state
        stateMachine.changeState("STANDING", "INITIAL");


    }

// Player methods...

void Player::update() {
    // check if currentState is nullptr
    stateMachine.update();
        
}

void Player::draw() const {
    // TODO draw the player as a circle
    glPushMatrix();
    glTranslatef(position.x, position.y, 0.0f);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        float degInRad = i * M_PI / 180;
        glVertex2f(cos(degInRad) * size, sin(degInRad) * size);
    }
    glEnd();
    glPopMatrix();
    
}

void Player::associateInput(std::string commandName) {
    
    // add to command list
    inputList.push_back(commandName);
}

// get for state machine
StateMachine& Player::getStateMachine() {
    return stateMachine;
}

// getter and setter input list
std::vector<std::string> Player::getInputList() {
    return inputList;
}

void Player::setInputList(std::vector<std::string> inputList) {
    this->inputList = inputList;
}

void Player::clearInputList() {
    inputList.clear();
}