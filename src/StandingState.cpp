#include "State.h"
#include "Player.h"


void StandingState::update() {
    // update position of hitbox observers to current player position
    updateBoxes();
}

void StandingState::enter(std::string command) {
    createBoxes();
    if (command == "MOVE_UP" || command == "MOVE_DOWN" || command == "MOVE_LEFT" || command == "MOVE_RIGHT" || command == "CROUCH" || command == "DASH") {
        onCommand(command);
    }
}

void StandingState::exit() {
    deleteBoxes();
    // Perform any cleanup tasks when exiting the StandingState
}

// Modify the StandingState.cpp file
void StandingState::handleInput() {

    std::vector<std::string> inputList = player->getInputHandler().getInputList();

    // Analyze inputList and perform state transitions accordingly

    if (std::find(inputList.begin(), inputList.end(), "CROUCH") != inputList.end()) {
        player->getStateMachine().applyCommand("CROUCH");
    } 
    if (std::find(inputList.begin(), inputList.end(), "DASH") != inputList.end()) {
        player->getStateMachine().applyCommand("DASH");
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

void StandingState::onCommand(std::string command) {
    if (command == "MOVE_UP") {
        player->getStateMachine().changeState("MOVING", command);
    } else if (command == "MOVE_DOWN") {
        player->getStateMachine().changeState("MOVING", command);
    } else if (command == "MOVE_LEFT") {
        player->getStateMachine().changeState("MOVING", command);
    } else if (command == "MOVE_RIGHT") {
        player->getStateMachine().changeState("MOVING", command);
    } else if (command == "CROUCH") {
        player->getStateMachine().changeState("CROUCHING", command);
    } else if (command == "DASH") {
        player->getStateMachine().changeState("DASHING", command);
    }
}

void StandingState::createBoxes() {
    // create hitbox observers
    auto hoc = std::make_unique<HitboxObserverCollection>();
    auto ho = std::make_shared<HitboxObserver>(player);
    hoc->hitboxObservers.push_back(ho);
    player->getHitboxManager().addHitboxObserver(ho);
    setHitboxObserverCollection(std::move(hoc));
}

void StandingState::deleteBoxes() {
    // Get the hitbox observer collection
    auto hoc = getHitboxObserverCollection();
    // Delete hitbox observers
    for (auto& ho : hoc->hitboxObservers) {
        // Remove hitbox observer
        player->getHitboxManager().removeHitboxObserver(ho);
    }
    setHitboxObserverCollection(nullptr);
}

void StandingState::updateBoxes() {
    // Get the hitbox observer collection
    auto hoc = getHitboxObserverCollection();
    for (auto& ho : hoc->hitboxObservers) {
        ho->getEntity()->setPosition(player->getPhysics().getPosition());
    }
}
