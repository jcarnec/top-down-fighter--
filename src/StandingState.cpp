#include "State.h"
#include "Player.h"
#include "HitboxManager.h"

void StandingState::update() {
    // update position of hitbox observers to current player position
}

void StandingState::enter(std::string command) {
    if (command == "MOVE_UP" || command == "MOVE_DOWN" || command == "MOVE_LEFT" || command == "MOVE_RIGHT" || command == "CROUCH" || command == "DASH") {
        onCommand(command);
    }
}

void StandingState::exit() {
    // Perform any cleanup tasks when exiting the StandingState
}

// Modify the StandingState.cpp file
void StandingState::handleInput() {

    std::vector<std::string> inputList = player->getComponent<InputHandler>()->getInputList();

    if (std::find(inputList.begin(), inputList.end(), "CROUCH") != inputList.end()) {
        player->getComponent<StateMachine>()->applyCommand("CROUCH");
    } 
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
}

void StandingState::onCommand(std::string command) {
    if (command == "MOVE_UP") {
        player->getComponent<StateMachine>()->changeState("MOVING", command);
    } else if (command == "MOVE_DOWN") {
        player->getComponent<StateMachine>()->changeState("MOVING", command);
    } else if (command == "MOVE_LEFT") {
        player->getComponent<StateMachine>()->changeState("MOVING", command);
    } else if (command == "MOVE_RIGHT") {
        player->getComponent<StateMachine>()->changeState("MOVING", command);
    } else if (command == "CROUCH") {
        player->getComponent<StateMachine>()->changeState("CROUCHING", command);
    } else if (command == "DASH") {
        player->getComponent<StateMachine>()->changeState("DASHING", command);
    }
}

void StandingState::createBoxes() {
    // create hitbox observers
    auto hoc = std::make_unique<HitboxObserverCollection>();
    auto ho = std::make_shared<HitboxObserver>(player, "StandingStateHurtbox");
    hoc->hitboxObservers.push_back(ho);
    player->getSharedComponent<HitboxManager>()->addHitboxObserver(ho);
    setHitboxObserverCollection(std::move(hoc));
}

void StandingState::deleteBoxes() {
    // Get the hitbox observer collection
    auto hoc = getHitboxObserverCollection();
    // Delete hitbox observers
    for (auto& ho : hoc->hitboxObservers) {
        // Remove hitbox observer
        player->getSharedComponent<HitboxManager>()->removeHitboxObserver(ho);
    }
    setHitboxObserverCollection(nullptr);
}

void StandingState::updateBoxes() {
    // Get the hitbox observer collection
    auto hoc = getHitboxObserverCollection();
    for (auto& ho : hoc->hitboxObservers) {
        ho->getEntity()->setPosition(player->getComponent<BasicPhysicsComponent>()->getPosition());
    }
}
