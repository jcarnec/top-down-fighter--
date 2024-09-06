
#include "Hitbox.h"
#include <algorithm>
#include <memory>

void Hitbox::attach(std::shared_ptr<HitboxObserver> observer) {
  observers_.push_back(observer);
  }
void Hitbox::detach(std::shared_ptr<HitboxObserver> observer) {
  observers_.erase(std::remove(observers_.begin(), observers_.end(), observer), observers_.end());
}

void Hitbox::notify() {
  for(std::shared_ptr<HitboxObserver> observer : observers_) {
    observer->notify(this);
  }
}