// Subject.cpp

#include "Subject.h"

template<typename T>
void Subject<T>::attach(T* observer) {
  observers_.push_back(observer);
}

template<typename T>  
void Subject<T>::detach(T* observer) {
  observers_.erase(std::remove(observers_.begin(), observers_.end(), observer), observers_.end());
}

template<typename T>
void Subject<T>::notify() {
  for(T* observer : observers_) {
    observer->update(this);
  }
}

