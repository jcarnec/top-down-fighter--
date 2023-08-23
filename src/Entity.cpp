// Entity.cpp
#include "Entity.h"


Entity::Entity(glm::vec2 position, float size, float moveSpeed)
    : position(position), size(size), moveSpeed(moveSpeed) {
    // Constructor implementation
}

glm::vec2 Entity::getPosition() const {
    return position;
}

void Entity::setPosition(glm::vec2 newPosition) {
    position = newPosition;
}

float Entity::getSize() const {
    return size;
}

void Entity::setSize(float newRadius) {
    size = newRadius;
}

float Entity::getMoveSpeed() const {
    return moveSpeed;
}

void Entity::setMoveSpeed(float speed) {
    moveSpeed = speed;
}
