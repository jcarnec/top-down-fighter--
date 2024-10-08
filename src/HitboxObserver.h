/**
 * @file HitboxObserver.h
 * @brief Declares the observer interface for Hitbox subjects
 */

#pragma once
#include <sstream>
#include "Observer.h"
#include "Shape.h"
#include <glm/glm.hpp>
#include <string>
#include "Entity.h"


class Hitbox;

/**
 * @class HitboxObserver
 * @brief Observer interface for classes that need to monitor Hitbox subjects
 */
class HitboxObserver : public Observer<Hitbox>
{

public:
  /**
   * Called when the observed Hitbox changes
   * @param subject The Hitbox that changed
   */
  void notify(Hitbox *subject) override;

  // constructor
  HitboxObserver(Entity* entity, std::string hurtboxName) : entity(entity) {
    name = entity->getId() + ", " + hurtboxName;
  }

  // getters and setters
  Entity* getEntity() { return entity; }
  void setEntity(Entity* entity) { this->entity = entity; }

  std::string name;

  void log() {
    std::ostringstream oss;
    oss << "(" << entity->getPosition().x << "," << entity->getPosition().y << "), " << name;
    std::cout << oss.str() << std::endl;
  }

  void onGettingHit(Hitbox *hb);

private:
private:
  Entity *entity;
};
