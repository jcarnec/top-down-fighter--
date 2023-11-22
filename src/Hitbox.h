/**
 * @file Hitbox.h
 * @brief Implements a hitbox Subject for the Observer pattern 
*/

#pragma once

#include "Subject.h"
#include "HitboxObserver.h"
#include <glm/glm.hpp>
#include "Shape.h"





/**
 * @class Hitbox
 * @brief A hitbox that acts as a subject in the Observer pattern.
*/ 
class Hitbox : public Subject<HitboxObserver> {

public:

  // constructor
  Hitbox(glm::vec2 position, Shape shape, int damage, glm::vec2 knockback) :
    position(position), shape(shape), damage(damage), knockback(knockback) {}

  // Implement Subject interface
  void attach(HitboxObserver* observer) override;
  void detach(HitboxObserver* observer) override;
  void notify() override;

private:

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
  // Shape
  Shape shape;
  // Damage
  int damage;
  // Knockback
  glm::vec2 knockback;
  std::vector<HitboxObserver*> observers_;



};


// Shape interface
