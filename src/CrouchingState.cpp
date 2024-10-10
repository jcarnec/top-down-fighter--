
#include "State.h"
#include "Player.h"
#include <glm/glm.hpp>
#include <iostream>


void CrouchingState::update() {
    // Update logic for moving state
    player->getComponent<BasicPhysicsComponent>()->applyForce(directionOfMovement * player->getComponent<BasicPhysicsComponent>()->getMoveForce());
    directionOfMovement = glm::vec2(0.0f, 0.0f);
}

// Inside CrouchingState implementation
void CrouchingState::enter(std::string command) {
    // Perform any cleanup tasks when exiting the CrouchingState
    const float playerFriction = player->getComponent<BasicPhysicsComponent>()->getFriction();
    player->getComponent<BasicPhysicsComponent>()->setFriction(playerFriction + crouchingStateFriction);
    const float playerMoveForce = player->getComponent<BasicPhysicsComponent>()->getMoveForce();
    player->getComponent<BasicPhysicsComponent>()->setMoveForce(playerMoveForce * crouchingStateMoveForceMultiplier);
    const float playerMaxSpeed = player->getComponent<BasicPhysicsComponent>()->getMaxSpeed();
    player->getComponent<BasicPhysicsComponent>()->setMaxSpeed(playerMaxSpeed * crouchingStateMaxSpeedMultiplier);

    // Perform any setup tasks when entering the StandingState
    // if command is MOVE_UP, then accelerate player upwards
    if (command == "MOVE_UP" || command == "MOVE_DOWN" || command == "MOVE_LEFT" || command == "MOVE_RIGHT" || command == "EXIT_CROUCH" || command == "DASH") {
        onCommand(command);
    }
}

void CrouchingState::exit() {
    // Perform any cleanup tasks when exiting the CrouchingState
    const float playerFriction = player->getComponent<BasicPhysicsComponent>()->getFriction();
    player->getComponent<BasicPhysicsComponent>()->setFriction(playerFriction - crouchingStateFriction);
    const float playerMoveForce = player->getComponent<BasicPhysicsComponent>()->getMoveForce();
    player->getComponent<BasicPhysicsComponent>()->setMoveForce(playerMoveForce / crouchingStateMoveForceMultiplier);
    const float playerMaxSpeed = player->getComponent<BasicPhysicsComponent>()->getMaxSpeed();
    player->getComponent<BasicPhysicsComponent>()->setMaxSpeed(playerMaxSpeed / crouchingStateMaxSpeedMultiplier);
}

// Other methods specific to CrouchingState...
void CrouchingState::handleInput() {
    // Get inputList from player
    // Get inputList from player
    std::vector<std::string> inputList = player->getInputHandler().getInputList();

    // Analyze inputList and perform state transitions accordingly
    if (std::find(inputList.begin(), inputList.end(), "DASH") != inputList.end()) {
        player->getComponent<StateMachine>()->applyCommand("DASH");
    } 
    if (std::find(inputList.begin(), inputList.end(), "UP") != inputList.end()) {
        player->getComponent<StateMachine>()->applyCommand("MOVE_UP");
    } 
    if (std::find(inputList.begin(), inputList.end(), "DOWN") != inputList.end()) {
        player->getComponent<StateMachine>()->applyCommand("MOVE_DOWN");
    }
    if (std::find(inputList.begin(), inputList.end(), "LEFT") != inputList.end()) {
        player->getComponent<StateMachine>()->applyCommand("MOVE_LEFT");
    }
    if (std::find(inputList.begin(), inputList.end(), "RIGHT") != inputList.end()) {
        player->getComponent<StateMachine>()->applyCommand("MOVE_RIGHT");
    }
    if (std::find(inputList.begin(), inputList.end(), "CROUCH") == inputList.end()) {
        player->getComponent<StateMachine>()->applyCommand("EXIT_CROUCH");
    } 

}


void CrouchingState::onCommand(std::string command) {
    if (command == "MOVE_UP") {
        directionOfMovement += glm::vec2(0.0f, 1.0f);
    } else if (command == "MOVE_DOWN") {
        directionOfMovement += glm::vec2(0.0f, -1.0f);
    } else if (command == "MOVE_LEFT") {
        directionOfMovement += glm::vec2(-1.0f, 0.0f);
    } else if (command == "MOVE_RIGHT") {
        directionOfMovement += glm::vec2(1.0f, 0.0f);
    } else if (command == "EXIT_CROUCH") {
        player->getComponent<StateMachine>()->changeState("STANDING", command);
    } else if (command == "DASH") {
        player->getComponent<StateMachine>()->changeState("DASHING", command);
    }
    // // log all physics values to console
    // std::cout << "==== Start of frame =======" << std::endl;
    // std::cout << "Acceleration: " << player->getComponent<BasicPhysicsComponent>().getAcceleration().x << ", " << player->getComponent<BasicPhysicsComponent>()->getAcceleration().y << std::endl;
    // std::cout << "Velocity: " << player->getComponent<BasicPhysicsComponent>().getVelocity().x << ", " << player->getComponent<BasicPhysicsComponent>()->getVelocity().y << std::endl;
    // std::cout << "Position: " << player->getComponent<BasicPhysicsComponent>().getPosition().x << ", " << player->getComponent<BasicPhysicsComponent>()->getPosition().y << std::endl;
    // std::cout << "Friction: " << player->getComponent<BasicPhysicsComponent>().getFriction() << std::endl;
    // std::cout << "Move Speed: " << player->getComponent<BasicPhysicsComponent>().getMoveAcceleration() << std::endl;
    // std::cout << "==== Start of frame =======" << std::endl;
}
void CrouchingState::createBoxes() {
    // Implementation of createBoxes
}

void CrouchingState::deleteBoxes() {
    // Implementation of deleteBoxes
}

void CrouchingState::updateBoxes() {
    // Implementation of updateBoxes
}


