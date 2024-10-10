#include "Player.h"
#include <GL/glut.h>
#include <cmath>
#include <iostream>
#include "HitboxManager.h"

// #include <memory> // Make sure to include this header for std::make_unique


// Player constructor...
Player::Player(glm::vec2 position, Shape shape, std::shared_ptr<HitboxManager> hm)
    : Entity(position, shape) {
   // Associate commands with keys in the inputMap

        addComponent<BasicPhysicsComponent>();
        addComponent<StateMachine>();
        addSharedComponent<HitboxManager>(hm);
        // Register states with the state machine
        getComponent<StateMachine>()->registerState("STANDING", std::make_unique<StandingState>(this, "STANDING"));
        getComponent<StateMachine>()->registerState("MOVING", std::make_unique<MovingState>(this, "MOVING"));
        getComponent<StateMachine>()->registerState("CROUCHING", std::make_unique<CrouchingState>(this, "CROUCHING"));
        getComponent<StateMachine>()->registerState("DASHING", std::make_unique<DashingState>(this, "DASHING"));
        
        // Set the current player for the state machine
        getComponent<StateMachine>()->setCurrentPlayer(this);
        
        // Initial state
        getComponent<StateMachine>()->changeState("STANDING", "INITIAL");

        // Initialize the input handler
        inputHandler = std::make_unique<InputHandler>(*this);

        inputHandler->initializeKeyBindings();

    }

// Player methods...

void Player::update() {
    // check if currentState is nullptr
    getComponent<StateMachine>()->update();
        
}

void Player::draw() {
    getComponent<StateMachine>()->draw();
}
