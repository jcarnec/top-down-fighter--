#include "State.h"
#include "Player.h"
#include <glm/glm.hpp>


void MovingState::update() {
    // Update logic for moving state
}

// Inside MovingState implementation
void MovingState::enter() {
    // Perform any setup tasks when entering the MovingState
}

void MovingState::exit() {
    // Perform any cleanup tasks when exiting the MovingState
}

// Other methods specific to MovingState...
void MovingState::handleInput(std::vector<std::string> inputList) {
    // Analyze inputList and perform state transitions accordingly
    if (std::find(inputList.begin(), inputList.end(), "forward") != inputList.end()) {
        player->getStateMachine().changeState("RunningState");
    }
    if (std::find(inputList.begin(), inputList.end(), "forward") != inputList.end() &&
        std::find(inputList.begin(), inputList.end(), "attack") != inputList.end()) {
        player->getStateMachine().changeState("LungeAttackState");
    }
}


