#include "State.h"
#include "Player.h"
#include <glm/glm.hpp>
#include <iostream>
#include "HitboxManager.h"


void DashingState::update() {
    // Update logic for moving state
    player->getComponent<BasicPhysicsComponent>()->applyForce(directionOfMovement * player->getComponent<BasicPhysicsComponent>()->getMoveForce());
    directionOfMovement = glm::vec2(0.0f, 0.0f);
    if(stateFrameCount >= DURATION) {
        player->getComponent<StateMachine>()->changeState("STANDING", "DASH_END");
    }
}

// Inside DashingState implementation
void DashingState::enter(std::string command) {
    std::cout << "Entering DashingState" << std::endl;
    glm::vec2 normalizedVelocity = glm::normalize(player->getComponent<BasicPhysicsComponent>()->getVelocity());
    if(glm::length(normalizedVelocity) > 0.0f) {
        player->getComponent<BasicPhysicsComponent>()->applyEForce(normalizedVelocity * dashForce);
    }
    if (command == "MOVE_UP" || command == "MOVE_DOWN" || command == "MOVE_LEFT" || command == "MOVE_RIGHT" || command == "CROUCH") {
        onCommand(command);
    }
}

void DashingState::exit() {
    // Perform any cleanup tasks when exiting the DashingState
    std::cout << "Exiting DashingState" << std::endl;
}

// Other methods specific to DashingState...
void DashingState::handleInput() {
    // Get inputList from player
    std::vector<std::string> inputList = player->getComponent<InputHandler>()->getInputList();

    // Analyze inputList and perform state transitions accordingly

    if (std::find(inputList.begin(), inputList.end(), "CROUCH") != inputList.end()) {
        player->getComponent<StateMachine>()->applyCommand("CROUCH");
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


void DashingState::onCommand(std::string command) {
    if (command == "CROUCH") {
        player->getComponent<StateMachine>()->changeState("CROUCHING", command);
    }
    if (command == "MOVE_UP") {
        directionOfMovement += glm::vec2(0.0f, 1.0f);
    } else if (command == "MOVE_DOWN") {
        directionOfMovement += glm::vec2(0.0f, -1.0f);
    } else if (command == "MOVE_LEFT") {
        directionOfMovement += glm::vec2(-1.0f, 0.0f);
    } else if (command == "MOVE_RIGHT") {
        directionOfMovement += glm::vec2(1.0f, 0.0f);
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

void DashingState::createBoxes() {
    // create hitbox observers
   auto hoc = std::make_unique<HitboxObserverCollection>();
    auto ho = std::make_shared<HitboxObserver>(player, "DashingStateHurtbox");
    hoc->hitboxObservers.push_back(ho);
    player->getSharedComponent<HitboxManager>()->addHitboxObserver(ho);
    setHitboxObserverCollection(std::move(hoc));

    // create hitboxes
    auto hc = std::make_unique<HitboxCollection>();
    auto hb = std::make_shared<Hitbox>(player, 1, glm::vec2(0, 0), "DashingStateHitbox");
    hc->hitboxes.push_back(hb);
    player->getSharedComponent<HitboxManager>()->addHitbox(hb);
    setHitboxCollection(std::move(hc));
}

void DashingState::deleteBoxes() {
    // delete hitbox observers
    for (auto& ho : getHitboxObserverCollection()->hitboxObservers) {
        player->getSharedComponent<HitboxManager>()->removeHitboxObserver(ho);
    }
    setHitboxObserverCollection(nullptr);

    // delete hitboxes
    for (auto& hb : getHitboxCollection()->hitboxes) {
        player->getSharedComponent<HitboxManager>()->removeHitbox(hb);
    }   
    setHitboxCollection(nullptr);
}

void DashingState::updateBoxes() {
    for (auto& ho : getHitboxObserverCollection()->hitboxObservers) {
        ho->getEntity()->setPosition(player->getComponent<BasicPhysicsComponent>()->getPosition());
    }

    for (auto& hb : getHitboxCollection()->hitboxes) {
        hb->getEntity()->setPosition(player->getComponent<BasicPhysicsComponent>()->getPosition());
    }

    for (auto& hb : getHitboxCollection()->hitboxes) {
        hb->notify();
    }

}



