#include "Player.h"
#include <GL/glut.h>
#include <cmath>
#include <iostream>
// #include <memory> // Make sure to include this header for std::make_unique


// Player constructor...
Player::Player(glm::vec2 position, float size)
    : StateMachineEntity(position, size) {
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

    glPushMatrix();
    glColor3f(0.0f, 1.0f, 0.0f); // Set line color to red
    glTranslatef(getPhysics().getPosition().x, getPhysics().getPosition().y, 0.0f);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        float degInRad = i * M_PI / 180;
        glVertex2f(cos(degInRad) * size, sin(degInRad) * size);
    }
    glEnd();

    // draw a separate line to show the direction the player is moving
    glm::vec2 velocity = getPhysics().getVelocity();
    glm::vec2 normalizedVelocity = glm::normalize(velocity);
    glm::vec2 direction = normalizedVelocity * size;

    // draw the line
    glBegin(GL_LINES);
    glColor3f(1.0f, 0.0f, 0.0f); // Set line color to red
    glVertex2f(0.0f, 0.0f); // Starting point of the line (center of the player)
    glVertex2f(direction.x, direction.y); // Ending point of the line
    glEnd();

    glPopMatrix();

}

void Player::associateInput(std::string commandName) {
    

    // add to command list
    inputList.push_back(commandName);
}

void Player::clearInputList() {
    inputList.clear();
}