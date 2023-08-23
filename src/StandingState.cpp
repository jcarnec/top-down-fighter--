#include "State.h"
#include "Player.h"


void StandingState::update() {
    // Update logic for standing state
}

void StandingState::enter(std::string command) {
    // Perform any setup tasks when entering the StandingState
}

void StandingState::exit() {
    // Perform any cleanup tasks when exiting the StandingState
}

// Modify the StandingState.cpp file
void StandingState::handleInput() {

    std::vector<std::string> inputList = player->getInputList();

    // Analyze inputList and perform state transitions accordingly
    if (std::find(inputList.begin(), inputList.end(), "UP") != inputList.end()) {
        player->getStateMachine().applyCommand("MOVE_UP");
    }
}

void StandingState::onCommand(std::string command) {
    if (command == "MOVE_UP") {
        player->getStateMachine().changeState("MOVING", command);
    }
}

void StandingState::clearInputList() {
    player->clearInputList();
}

