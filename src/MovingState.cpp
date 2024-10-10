#include "State.h"
#include "Player.h"
#include <glm/glm.hpp>
#include <iostream>
#include "HitboxManager.h"


void MovingState::update() {
    // Update logic for moving state
    player->getComponent<BasicPhysicsComponent>()->applyForce(directionOfMovement * player->getComponent<BasicPhysicsComponent>()->getMoveForce());
    directionOfMovement = glm::vec2(0.0f, 0.0f);
}

// Inside MovingState implementation
void MovingState::enter(std::string command) {
    // Perform any setup tasks when entering the StandingState
    // if command is MOVE_UP, then accelerate player upwards
    if (command == "MOVE_UP" || command == "MOVE_DOWN" || command == "MOVE_LEFT" || command == "MOVE_RIGHT" || command == "CROUCH" || command == "DASH") {
        onCommand(command);
    }
}

void MovingState::exit() {
    // Perform any cleanup tasks when exiting the MovingState
    // update hitboxes
}

// Other methods specific to MovingState...
void MovingState::handleInput() {
    // Get inputList from player
    std::vector<std::string> inputList = player->getInputHandler().getInputList();

    // Analyze inputList and perform state transitions accordingly

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


void MovingState::onCommand(std::string command) {

    if (command == "MOVE_UP") {
        directionOfMovement += glm::vec2(0.0f, 1.0f);
    } else if (command == "MOVE_DOWN") {
        directionOfMovement += glm::vec2(0.0f, -1.0f);
    } else if (command == "MOVE_LEFT") {
        directionOfMovement += glm::vec2(-1.0f, 0.0f);
    } else if (command == "MOVE_RIGHT") {
        directionOfMovement += glm::vec2(1.0f, 0.0f);
    } else if (command == "CROUCH") {
        player->getComponent<StateMachine>()->changeState("CROUCHING", command);
    } else if (command == "DASH") {
        player->getComponent<StateMachine>()->changeState("DASHING", command);
    }

    // // log all physics values to console
    // std::cout << "==== Start of frame =======" << std::endl;
    // std::cout << "Acceleration: " << player->getComponent<BasicPhysicsComponent>()->getAcceleration().x << ", " << player->getComponent<BasicPhysicsComponent>()->getAcceleration().y << std::endl;
    // std::cout << "Velocity: " << player->getComponent<BasicPhysicsComponent>()->getVelocity().x << ", " << player->getComponent<BasicPhysicsComponent>()->getVelocity().y << std::endl;
    // std::cout << "Position: " << player->getComponent<BasicPhysicsComponent>()->getPosition().x << ", " << player->getComponent<BasicPhysicsComponent>()->getPosition().y << std::endl;
    // std::cout << "Friction: " << player->getComponent<BasicPhysicsComponent>()->getFriction() << std::endl;
    // std::cout << "Move Speed: " << player->getComponent<BasicPhysicsComponent>()->getMoveForce() << std::endl;
    // std::cout << "==== Start of frame =======" << std::endl;
}

void MovingState::createBoxes() {
    // Implementation of createBoxes
    auto hoc = std::make_unique<HitboxObserverCollection>();
    auto ho = std::make_shared<HitboxObserver>(player, "MovingStateHurtbox");
    hoc->hitboxObservers.push_back(ho);
    player->getSharedComponent<HitboxManager>()->addHitboxObserver(ho);
    setHitboxObserverCollection(std::move(hoc));
}

void MovingState::deleteBoxes() {
    // Get the hitbox observer collection
    auto hoc = getHitboxObserverCollection();
    // Delete hitbox observers
    for (auto& ho : hoc->hitboxObservers) {
        // Remove hitbox observer
        player->getSharedComponent<HitboxManager>()->removeHitboxObserver(ho);
    }
    setHitboxObserverCollection(nullptr);
}

void MovingState::updateBoxes() {
    // Get the hitbox observer collection
    auto hoc = getHitboxObserverCollection();
    for (auto& ho : hoc->hitboxObservers) {
        ho->getEntity()->setPosition(player->getComponent<BasicPhysicsComponent>()->getPosition());
    }
}