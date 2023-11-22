
#include "Hitbox.h"
#include <algorithm>

void Hitbox::attach(HitboxObserver* observer) {
  observers_.push_back(observer);
  }
void Hitbox::detach(HitboxObserver* observer) {
  observers_.erase(std::remove(observers_.begin(), observers_.end(), observer), observers_.end());
}

void Hitbox::notify() {
  for(HitboxObserver* observer : observers_) {
    observer->update(this);
  }
}