#include "State.h"
#include "Player.h"
#include <glm/glm.hpp>
#include <iostream>


void MovingState::update() {
    // Update logic for moving state
    player->getPhysics().applyPhysics();
    player->getPhysics().setAcceleration(glm::vec2(0.0f, 0.0f));
}

// Inside MovingState implementation
void MovingState::enter(std::string command) {
    // Perform any setup tasks when entering the StandingState
    // if command is MOVE_UP, then accelerate player upwards
    if (command == "MOVE_UP" || command == "MOVE_DOWN" || command == "MOVE_LEFT" || command == "MOVE_RIGHT") {
        onCommand(command);
    }
}

void MovingState::exit() {
    // Perform any cleanup tasks when exiting the MovingState
}

// Other methods specific to MovingState...
void MovingState::handleInput() {

    // get inputList from player
    std::vector<std::string> inputList = player->getInputList();
    // Analyze inputList and perform state transitions accordingly
    if (std::find(inputList.begin(), inputList.end(), "UP") != inputList.end()) {
        player->getStateMachine().applyCommand("MOVE_UP");
    }
    if (std::find(inputList.begin(), inputList.end(), "DOWN") != inputList.end()) {
        player->getStateMachine().applyCommand("MOVE_DOWN");
    }
    if (std::find(inputList.begin(), inputList.end(), "LEFT") != inputList.end()) {
        player->getStateMachine().applyCommand("MOVE_LEFT");
    }
    if (std::find(inputList.begin(), inputList.end(), "RIGHT") != inputList.end()) {
        player->getStateMachine().applyCommand("MOVE_RIGHT");
    }
}

void MovingState::onCommand(std::string command) {
    glm::vec2 directionOfMovement = glm::vec2(0.0f, 0.0f);
    if (command == "MOVE_UP") {
        directionOfMovement = glm::vec2(0.0f, 1.0f);
    } else if (command == "MOVE_DOWN") {
        directionOfMovement = glm::vec2(0.0f, -1.0f);
    } else if (command == "MOVE_LEFT") {
        directionOfMovement = glm::vec2(-1.0f, 0.0f);
    } else if (command == "MOVE_RIGHT") {
        directionOfMovement = glm::vec2(1.0f, 0.0f);
    }

    player->getPhysics().setAcceleration(directionOfMovement * player->getPhysics().getMoveAcceleration());

    // // log all physics values to console
    // std::cout << "==== Start of frame =======" << std::endl;
    // std::cout << "Acceleration: " << player->getPhysics().getAcceleration().x << ", " << player->getPhysics().getAcceleration().y << std::endl;
    // std::cout << "Velocity: " << player->getPhysics().getVelocity().x << ", " << player->getPhysics().getVelocity().y << std::endl;
    // std::cout << "Position: " << player->getPhysics().getPosition().x << ", " << player->getPhysics().getPosition().y << std::endl;
    // std::cout << "Friction: " << player->getPhysics().getFriction() << std::endl;
    // std::cout << "Move Speed: " << player->getPhysics().getMoveAcceleration() << std::endl;
    // std::cout << "==== Start of frame =======" << std::endl;
}

void MovingState::clearInputList() {
    player->clearInputList();
}


