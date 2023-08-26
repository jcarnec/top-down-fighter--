#include "State.h"
#include "Player.h"
#include <glm/glm.hpp>
#include <iostream>


void DashingState::update() {
    // Update logic for moving state
    player->getPhysics().applyForce(directionOfMovement * player->getPhysics().getMoveForce());
    directionOfMovement = glm::vec2(0.0f, 0.0f);
    std::cout << "stateFrameCount: " << stateFrameCount << std::endl;
    if(stateFrameCount >= DURATION) {
        player->getStateMachine().changeState("STANDING", "DASH_END");
    }
}

// Inside DashingState implementation
void DashingState::enter(std::string command) {
    // Perform any setup tasks when entering the StandingState
    // if command is MOVE_UP, then accelerate player upwards
    std::cout << "Entering DashingState" << std::endl;
    // get normalized velocity vector
    glm::vec2 normalizedVelocity = glm::normalize(player->getPhysics().getVelocity());
    player->getPhysics().applyEForce(normalizedVelocity * dashForce);
    if (command == "MOVE_UP" || command == "MOVE_DOWN" || command == "MOVE_LEFT" || command == "MOVE_RIGHT" || command == "CROUCH") {
        onCommand(command);
    }
}

void DashingState::exit() {
    // Perform any cleanup tasks when exiting the DashingState
    std::cout << "Exiting DashingState" << std::endl;
}

// Other methods specific to DashingState...
void DashingState::handleInput() {
    // Get inputList from player
    std::vector<std::string> inputList = player->getInputHandler().getInputList();

    // Analyze inputList and perform state transitions accordingly

    if (std::find(inputList.begin(), inputList.end(), "CROUCH") != inputList.end()) {
        player->getStateMachine().applyCommand("CROUCH");
    } 
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


void DashingState::onCommand(std::string command) {
    if (command == "CROUCH") {
        player->getStateMachine().changeState("CROUCHING", command);
    }
    if (command == "MOVE_UP") {
        directionOfMovement += glm::vec2(0.0f, 1.0f);
    } else if (command == "MOVE_DOWN") {
        directionOfMovement += glm::vec2(0.0f, -1.0f);
    } else if (command == "MOVE_LEFT") {
        directionOfMovement += glm::vec2(-1.0f, 0.0f);
    } else if (command == "MOVE_RIGHT") {
        directionOfMovement += glm::vec2(1.0f, 0.0f);
    }


    // // log all physics values to console
    // std::cout << "==== Start of frame =======" << std::endl;
    // std::cout << "Acceleration: " << player->getPhysics().getAcceleration().x << ", " << player->getPhysics().getAcceleration().y << std::endl;
    // std::cout << "Velocity: " << player->getPhysics().getVelocity().x << ", " << player->getPhysics().getVelocity().y << std::endl;
    // std::cout << "Position: " << player->getPhysics().getPosition().x << ", " << player->getPhysics().getPosition().y << std::endl;
    // std::cout << "Friction: " << player->getPhysics().getFriction() << std::endl;
    // std::cout << "Move Speed: " << player->getPhysics().getMoveForce() << std::endl;
    // std::cout << "==== Start of frame =======" << std::endl;
}



