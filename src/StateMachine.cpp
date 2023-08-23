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
            currentState->exit();
        }
        currentState = newStateIt->second.get();
        // eventually command will be a more complex object
        currentState->enter(command);
    }
}

void StateMachine::update() {
    if (currentState) {
        currentState->handleInput();
        currentState->update();
        // clear input list
        currentState->clearInputList();
        
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

/* === End of StateMachine.cpp === */
