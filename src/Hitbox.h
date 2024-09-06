/**
 * @file Hitbox.h
 * @brief Implements a hitbox Subject for the Observer pattern 
*/

#pragma once

#include "Subject.h"
#include "HitboxObserver.h"
#include <glm/glm.hpp>
#include "Shape.h"
#include <vector>
#include <memory>
#include <string>





/**
 * @class Hitbox
 * @brief A hitbox that acts as a subject in the Observer pattern.
*/ 
class Hitbox : public Subject<HitboxObserver> {

public:

  // constructor
  Hitbox(glm::vec2 position, Shape shape, int damage, glm::vec2 knockback, std::string ownerId) :
    position(position), shape(shape), damage(damage), knockback(knockback), ownerId(ownerId) {}

  // Implement Subject interface
  void attach(std::shared_ptr<HitboxObserver> observer) override;
  void detach(std::shared_ptr<HitboxObserver> observer) override;

  void notify() override;

  std::string getOwner() { return ownerId; }
  void setOwner(std::string ownerId) { this->ownerId = ownerId; }

  // World Position
  glm::vec2 getWorldPosition() { return worldPosition; }
  void setWorldPosition(glm::vec2 worldPosition) { this->worldPosition = worldPosition; }

  // Position
  glm::vec2 getPosition() { return position; }
  void setPosition(glm::vec2 position) { this->position = position; }

private:

  // getters and setters

  // Size
  float getSize() { return size; }
  void setSize(float size) { this->size = size; }

  // Shape
  Shape getShape() { return shape; }
  void setShape(Shape shape) { this->shape = shape; }

  // Damage
  int getDamage() { return damage; }
  void setDamage(int damage) { this->damage = damage; }

  // Knockback
  glm::vec2 getKnockback() { return knockback; }
  void setKnockback(glm::vec2 knockback) { this->knockback = knockback; }

  // Hitstun
  int getHitstun() { return glm::length(knockback); }

private:
  
  float size;
  glm::vec2 position;
  glm::vec2 worldPosition;
  // Shape
  Shape shape;
  // Damage
  int damage;
  // Knockback
  glm::vec2 knockback;
  std::vector<std::shared_ptr<HitboxObserver>> observers_;
  std::string ownerId;
};


