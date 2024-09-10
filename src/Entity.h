#ifndef ENTITY_H
#define ENTITY_H

#include "Shape.h"
#include <string>
#include <glm/vec2.hpp>

class Entity {
public:
    Entity(glm::vec2 position, Shape shape) : shape(shape) {
        setPosition(position);
        // generate unique id of length 10
        id = std::to_string(rand() % 1000000000);
    }

    virtual ~Entity() = default;

    virtual void update() = 0;
    virtual void draw() const = 0;

    Shape getShape() const { return shape; }
    void setShape(Shape shape) { this->shape = shape; }

    glm::vec2 getPosition() const { return position; }
    void setPosition(glm::vec2 position) { this->position = position; }

    std::string getId() const { return id; }
    void setId(std::string id) { this->id = id; }

protected:
    glm::vec2 position;
    Shape shape;
    std::string id = "default";
};

#endif // ENTITY_H