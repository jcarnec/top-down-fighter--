#include "Player.h"
#include <GL/glut.h>
#include <cmath>
#include <iostream>

// #include <memory> // Make sure to include this header for std::make_unique


// Player constructor...
Player::Player(glm::vec2 position, float size)
    : StateMachineEntity(position, size) {
   // Associate commands with keys in the inputMap

        // Register states with the state machine
        stateMachine.registerState("STANDING", std::make_unique<StandingState>(this, "STANDING"));
        stateMachine.registerState("MOVING", std::make_unique<MovingState>(this, "MOVING"));
        stateMachine.registerState("CROUCHING", std::make_unique<CrouchingState>(this, "CROUCHING"));
        stateMachine.registerState("DASHING", std::make_unique<DashingState>(this, "DASHING"));
        
        // Set the current player for the state machine
        stateMachine.setCurrentPlayer(this);
        
        // Initial state
        stateMachine.changeState("STANDING", "INITIAL");

        // Initialize the input handler
        inputHandler = std::make_unique<InputHandler>(*this);

        auto hc = std::make_unique<HitboxCollection>();
        hc->hitboxes.push_back(std::make_shared<Hitbox>(position, Circle(20.0f), 1, glm::vec2(0, 0)));
        
        stateMachine.getState("DASHING")->setHitboxCollection(std::move(hc));

    }

// Player methods...

void Player::update() {
    // check if currentState is nullptr
    stateMachine.update();
        
}

void Player::draw() const {
    stateMachine.draw();
}
