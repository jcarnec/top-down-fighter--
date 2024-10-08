#include "State.h"
#include "Player.h"
#include <glm/glm.hpp>
#include <iostream>


void MovingState::update() {
    // Update logic for moving state
    player->getPhysics().applyForce(directionOfMovement * player->getPhysics().getMoveForce());
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
    deleteBoxes();
}

// Other methods specific to MovingState...
void MovingState::handleInput() {
    // Get inputList from player
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
        player->getStateMachine().changeState("CROUCHING", command);
    } else if (command == "DASH") {
        player->getStateMachine().changeState("DASHING", command);
    }

    // // log all physics values to console
    // std::cout << "==== Start of frame =======" << std::endl;
    // std::cout << "Acceleration: " << player->getPhysics().getAcceleration().x << ", " << player->getPhysics().getAcceleration().y << std::endl;
    // std::cout << "Velocity: " << player->getPhysics().getVelocity().x << ", " << player->getPhysics().getVelocity().y << std::endl;
    // std::cout << "Position: " << player->getPhysics().getPosition().x << ", " << player->getPhysics().getPosition().y << std::endl;
    // std::cout << "Friction: " << player->getPhysics().getFriction() << std::endl;
    // std::cout << "Move Speed: " << player->getPhysics().getMoveForce() << std::endl;
    // std::cout << "==== Start of frame =======" << std::endl;
}

void MovingState::createBoxes() {
    // Implementation of createBoxes
    auto hoc = std::make_unique<HitboxObserverCollection>();
    auto ho = std::make_shared<HitboxObserver>(player);
    hoc->hitboxObservers.push_back(ho);
    player->getHitboxManager()->addHitboxObserver(ho);
    setHitboxObserverCollection(std::move(hoc));
}

void MovingState::deleteBoxes() {
    // Get the hitbox observer collection
    auto hoc = getHitboxObserverCollection();
    // Delete hitbox observers
    for (auto& ho : hoc->hitboxObservers) {
        // Remove hitbox observer
        player->getHitboxManager()->removeHitboxObserver(ho);
    }
    setHitboxObserverCollection(nullptr);
}

void MovingState::updateBoxes() {
    // Get the hitbox observer collection
    auto hoc = getHitboxObserverCollection();
    if (!hoc) {
        std::cerr << "Error: HitboxObserverCollection is null" << std::endl;
        return;
    }
    for (auto& ho : hoc->hitboxObservers) {
        ho->getEntity()->setPosition(player->getPhysics().getPosition());
    }
}