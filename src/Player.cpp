#include "Player.h"
#include <GL/glut.h>
#include <cmath>
#include "MoveCommand.h"

// Player constructor...
Player::Player(glm::vec2 position, float radius)
    : position(position), radius(radius), moveSpeed(0.005f), currentState(nullptr) {}

// Player methods...
void Player::move(glm::vec2 direction) {
    // check if currentState is nullptr
    if (currentState != nullptr) {
        currentState->move(this, direction);
    }
}

void Player::update() {
    // check if currentState is nullptr
    if (currentState == nullptr) {
        // set currentState to a new StandingState
        currentState = new StandingState();
    } else {
        currentState->update(this);
    }
}

void Player::draw() const {
    // draw a red circle the size of the player at the players position by push and pop matrix
    glPushMatrix();
    glTranslatef(position.x, position.y, 0.0f);
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        float degInRad = i * M_PI / 180.0f;
        glVertex2f(cos(degInRad) * radius, sin(degInRad) * radius);
    }
    glEnd();
    glPopMatrix();


    
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
    commandMap[command->name] = command; // Associate the command with the key
}

void Player::executeCommand(const std::string& key) {
    auto it = commandMap.find(key);
    if (it != commandMap.end()) {
        it->second->execute(); // Execute the command associated with the key
    }
}