/* === StateMachine.cpp === */
#include "StateMachine.h"
#include "State.h"


StateMachine::StateMachine() : currentState(nullptr) {}

void StateMachine::registerState(const std::string& stateName, std::shared_ptr<State> state) {
    states[stateName] = state;
}

void StateMachine::changeState(const std::string& stateName) {
    auto newStateIt = states.find(stateName);
    if (newStateIt != states.end()) {
        if (currentState) {
            currentState->exit();
        }
        currentState = newStateIt->second.get();
        currentState->enter();
    }
}

void StateMachine::update() {
    if (currentState) {
        currentState->update();
    }
}

void StateMachine::setCurrentPlayer(Player* player) {
    currentPlayer = player;
}

/* === End of StateMachine.cpp === */
