#include "Player.h"
#include <GL/glut.h>
#include <cmath>

// Player constructor...
Player::Player(glm::vec2 position, float radius)
    : position(position), radius(radius), moveSpeed(0.005f), currentState(nullptr) {}

// Player methods...
void Player::move(glm::vec2 direction) {
    currentState->move(this, direction);
}

void Player::update() {
    currentState->update(this);
}

void Player::draw() const {
    // Drawing logic...
}

void Player::setState(PlayerState* newState) {
    delete currentState; // Clean up previous state
    currentState = newState;
}

// Getter and setter methods implementation
glm::vec2 Player::getPosition() const {
    return position;
}

void Player::setPosition(glm::vec2 newPosition) {
    position = newPosition;
}

float Player::getRadius() const {
    return radius;
}

void Player::setRadius(float newRadius) {
    radius = newRadius;
}

float Player::getMoveSpeed() const {
    return moveSpeed;
}

void Player::setMoveSpeed(float speed) {
    moveSpeed = speed;
}

PlayerState* Player::getCurrentState() const {
    return currentState;
}

void Player::setCurrentState(PlayerState* newState) {
    setState(newState);
}

void Player::associateCommand(Command* command) {
    commandMap[command.name] = command; // Associate the command with the key
}

void Player::executeCommand(const std::string& key) {
    auto it = commandMap.find(key);
    if (it != commandMap.end()) {
        it->second->execute(); // Execute the command associated with the key
    }
}