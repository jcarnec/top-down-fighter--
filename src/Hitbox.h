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
class Hitbox : public Subject<HitboxObserver>
{

public:
  // constructor
  Hitbox(Entity* owner, int damage, glm::vec2 knockback, std::string hitboxName) : owner(owner), damage(damage), knockback(knockback) {
    name = owner->getId() + ", " + hitboxName;
  }

  // Implement Subject interface
  void attach(std::shared_ptr<HitboxObserver> observer) override;
  void detach(std::shared_ptr<HitboxObserver> observer) override;

  void notify() override;

  void onHit(HitboxObserver hbo) {
    std::cout << "I Hit!" << std::endl;
  };

public:
  // getters and setters

  // Size
  float getSize() { return size; }
  void setSize(float size) { this->size = size; }

  // Entity
  Entity* getOwner() { return owner; }
  void setOwner(Entity* owner) { this->owner = owner; }
  
  // Damage
  int getDamage() { return damage; }
  void setDamage(int damage) { this->damage = damage; }

  // Knockback
  glm::vec2 getKnockback() { return knockback; }
  void setKnockback(glm::vec2 knockback) { this->knockback = knockback; }

  // Hitstun
  int getHitstun() { return glm::length(knockback); }

  std::string name;

  void log() {
    std::ostringstream oss;
    oss << "(" << owner->getPosition().x << "," << owner->getPosition().y << "), " + name;
    std::cout << oss.str() << std::endl;
  }

  void onHitting(HitboxObserver hbo) {
    std::cout << "HIT" << std::endl;
  }

private:
  float size;
  // Shape
  Entity* owner;
  // Damage
  int damage;
  // Knockback
  glm::vec2 knockback;
  std::vector<std::shared_ptr<HitboxObserver>> observers_;
};
