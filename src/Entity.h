#ifndef ENTITY_H
#define ENTITY_H

#include "Shape.h"
#include <string>
#include <glm/vec2.hpp>
#include <memory>
#include <iostream>

class Entity {
public:
    Entity(glm::vec2 position, Shape shape) {
        setPosition(position);
        setShape(shape);
        id = std::to_string(rand() % 1000000000);
    }

    virtual ~Entity() = default;

    Shape getShape() const { return shape; }
    void setShape(Shape shape) { this->shape = shape; }

    glm::vec2 getPosition() const { return position; }
    void setPosition(glm::vec2 position) { 
        this->position = position; 
        this->shape.setGlobalPosition(position + shape.getPosition());
    }

    std::string getId() const { return id; }
    void setId(std::string id) { this->id = id; }

protected:
    glm::vec2 position;
    Shape shape;
    std::string id = "default";
};

#endif // ENTITY_H