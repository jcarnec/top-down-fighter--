
#include "StateMachineEntity.h"
#include <GL/glut.h>
#include <cmath>
// #include <memory> // Make sure to include this header for std::make_unique


// Player constructor...
StateMachineEntity::StateMachineEntity(glm::vec2 position, float size, float moveSpeed)
    : Entity(position, size, moveSpeed) {
    }

// Player methods...

void StateMachineEntity::update() {
    // check if currentState is nullptr
    stateMachine.update();
}

void StateMachineEntity::draw() const {}


StateMachine& StateMachineEntity::getStateMachine() {
    return stateMachine;
}
