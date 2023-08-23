#include "Player.h"
#include <GL/glut.h>
#include <cmath>
// #include <memory> // Make sure to include this header for std::make_unique


// Player constructor...
Player::Player(glm::vec2 position, float size, float moveSpeed)
    : position(position), size(size), moveSpeed(moveSpeed) {
   // Associate commands with keys in the inputMap

        inputMap["UP"] = 'w';
        inputMap["LEFT"] = 'a';
        inputMap["DOWN"] = 's';
        inputMap["RIGHT"] = 'd';


        // Register states with the state machine
        stateMachine.registerState("Standing", std::make_unique<StandingState>(this));
        stateMachine.registerState("Moving", std::make_unique<StandingState>(this));
        
        // Set the current player for the state machine
        stateMachine.setCurrentPlayer(this);
        
        // Initial state
        stateMachine.changeState("Standing");


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

// Getter and setter methods implementation
glm::vec2 Player::getPosition() const {
    return position;
}

void Player::setPosition(glm::vec2 newPosition) {
    position = newPosition;
}

float Player::getSize() const {
    return size;
}

void Player::setSize(float newRadius) {
    size = newRadius;
}

float Player::getMoveSpeed() const {
    return moveSpeed;
}

void Player::setMoveSpeed(float speed) {
    moveSpeed = speed;
}

void Player::associateInput(std::string commandName) {
    
    // add to command list
    inputList.push_back(commandName);
}

StateMachine Player::getStateMachine() {
    return stateMachine;
}
