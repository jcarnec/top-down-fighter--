/**
 * @file HitboxObserver.h
 * @brief Declares the observer interface for Hitbox subjects
*/

#pragma once 

#include "Observer.h"
#include "Shape.h"
#include <glm/glm.hpp>
#include <string>

class Hitbox;

/**
 * @class HitboxObserver
 * @brief Observer interface for classes that need to monitor Hitbox subjects
*/
class HitboxObserver : public Observer<Hitbox> {

public:
  
  /**
   * Called when the observed Hitbox changes
   * @param subject The Hitbox that changed
   */
  void notify(Hitbox* subject) override;

  // constructor
  HitboxObserver(glm::vec2 position, Shape shape, int damage, glm::vec2 knockback, std::string ownerId) :
    position(position), shape(shape), ownerId(ownerId) {}


  std::string getOwner() { return ownerId; }
  void setOwner(std::string ownerId) { this->ownerId = ownerId; }

  // getters and setters

  // Size
  float getSize() { return size; }
  void setSize(float size) { this->size = size; }

  // Position
  glm::vec2 getPosition() { return position; }
  void setPosition(glm::vec2 position) { this->position = position; }

  // Shape
  Shape getShape() { return shape; }
  void setShape(Shape shape) { this->shape = shape; }

private:

private:
  
  float size;
  glm::vec2 position;
  Shape shape;
  std::string ownerId;

  



};

