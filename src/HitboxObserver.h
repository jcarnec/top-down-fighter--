/**
 * @file HitboxObserver.h
 * @brief Declares the observer interface for Hitbox subjects
*/

#pragma once 

#include "Observer.h"


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
  void update(Hitbox* subject) override;

};

