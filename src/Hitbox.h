/**
 * @file Hitbox.h
 * @brief Implements a hitbox Subject for the Observer pattern 
*/

#pragma once

#include "Subject.h"
#include "HitboxObserver.h"

/**
 * @class Hitbox
 * @brief A hitbox that acts as a subject in the Observer pattern.
*/ 
class Hitbox : public Subject<HitboxObserver> {

public:

  // Implement Subject interface
  void attach(HitboxObserver* observer) override;
  void detach(HitboxObserver* observer) override;
  void notify() override;

  // Hitbox specific methods
  // ...

};

