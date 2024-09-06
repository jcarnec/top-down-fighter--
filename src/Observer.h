/**
 * @file Observer.h
 * @brief Declares the Observer interface for the Observer pattern
*/

#pragma once

#include "Subject.h"

/**
 * @class Observer
 * @brief The abstract Observer interface for the Observer pattern.
*/
template<typename T>
class Observer {

public:

  /**
   * Update this observer with data from the subject.
   * @param subject The subject being observed.
   */
  virtual void notify(T* subject) = 0;

};

