/* === StateMachine.cpp === */
#include "StateMachine.h"
#include "State.h"


// forward declaration
class Player;

StateMachine::StateMachine() : currentState(nullptr) {}

void StateMachine::registerState(const std::string& stateName, std::shared_ptr<State> state) {
    states[stateName] = state;
}

void StateMachine::changeState(const std::string& stateName, const std::string& command) {
    auto newStateIt = states.find(stateName);
    if (newStateIt != states.end()) {
        if (currentState) {
            currentState->deleteBoxes();
            currentState->exit();
        }
        currentState = newStateIt->second.get();
        // eventually command will be a more complex object
        currentState->createBoxes();
        currentState->enter(command);
    }
}

void StateMachine::update() {
    if (currentState) {
        currentState->stateFrameCount++;
        currentState->handleInput();
        currentState->update();
        currentState->physicsUpdate();
        currentState->updateBoxes();
    }
}

void StateMachine::setCurrentPlayer(Player* player) {
    currentPlayer = player;
}

void StateMachine::applyCommand(const std::string& command) {
    if (currentState) {
        currentState->onCommand(command);
    }
}

void StateMachine::draw() const {
    if (currentState) {
        currentState->draw();
    }
}

/* === End of StateMachine.cpp === */
