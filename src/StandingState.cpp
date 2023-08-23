#include "State.h"
#include "Player.h"


void StandingState::update() {
    // Update logic for standing state
}

void StandingState::enter() {
    // Perform any setup tasks when entering the StandingState
}

void StandingState::exit() {
    // Perform any cleanup tasks when exiting the StandingState
}

// Modify the StandingState.cpp file
void StandingState::handleInput(std::vector<std::string> inputList) {
    // Analyze inputList and perform state transitions accordingly
    if (std::find(inputList.begin(), inputList.end(), "forward") != inputList.end()) {
        player->getStateMachine().changeState("RunningState");
    }
    if (std::find(inputList.begin(), inputList.end(), "forward") != inputList.end() &&
        std::find(inputList.begin(), inputList.end(), "attack") != inputList.end()) {
        player->getStateMachine().changeState("LungeAttackState");
    }
}

