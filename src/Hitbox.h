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
  Hitbox(Entity* entity, int damage, glm::vec2 knockback, std::string hitboxName) : entity(entity), damage(damage), knockback(knockback) {
    name = entity->getId() + ", " + hitboxName;
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
  Entity* getEntity() { return entity; }
  void setEntity(Entity* entity) { this->entity = entity; }
  
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
    oss << "(" << entity->getPosition().x << "," << entity->getPosition().y << "), " + name;
    std::cout << oss.str() << std::endl;
  }

  void onHitting(HitboxObserver hbo) {
    std::cout << "HIT" << std::endl;
  }

private:
  float size;
  // Shape
  Entity* entity;
  // Damage
  int damage;
  // Knockback
  glm::vec2 knockback;
  std::vector<std::shared_ptr<HitboxObserver>> observers_;
};
