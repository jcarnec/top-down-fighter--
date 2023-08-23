#include "State.h"
#include "Player.h"
#include <glm/glm.hpp>


void MovingState::update() {
    // Update logic for moving state
    player->applyVelocity();
}

// Inside MovingState implementation
void MovingState::enter(std::string command) {
    // Perform any setup tasks when entering the StandingState
    // if command is MOVE_UP, then accelerate player upwards
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

    player->setVelocity(directionOfMovement * player->getMoveSpeed());
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
}

void MovingState::onCommand(std::string command) {
    if (command == "MOVE_UP") {
        // accelerate player
    }
}

void MovingState::clearInputList() {
    player->clearInputList();
}


