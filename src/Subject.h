/**
 * @file Subject.h 
 * @brief Declares the Subject interface for the Observer pattern
*/

#pragma once

#include <vector>

/**
 * @class Subject
 * @brief The abstract Subject interface for the Observer pattern.
*/
template<typename T>
class Subject {

public:

  /**
   * Attach an observer to this subject.
   * @param observer The observer to attach.
   */
  virtual void attach(T* observer) = 0;

  /**
   * Detach an observer from this subject.
   * @param observer The observer to detach.
   */ 
  virtual void detach(T* observer) = 0;

  /**
   * Notify all observers attached to this subject.
   */
  virtual void notify() = 0;

protected:
  
  /// List of observers attached to the subject
  std::vector<T*> observers_;

};

