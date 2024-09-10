/**
 * @file HitboxObserver.h
 * @brief Declares the observer interface for Hitbox subjects
 */

#pragma once

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
  HitboxObserver(Entity* entity) : entity(entity) {}

  // getters and setters
  Entity* getEntity() { return entity; }
  void setEntity(Entity* entity) { this->entity = entity; }

private:
private:
  Entity *entity;
};
