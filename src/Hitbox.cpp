
// Hitbox.cpp

#include "Hitbox.h"

void Hitbox::attach(HitboxObserver* observer) {
  Subject<HitboxObserver>::attach(observer);
}

void Hitbox::detach(HitboxObserver* observer) {
  Subject<HitboxObserver>::detach(observer); 
}

void Hitbox::notify() {
  Subject<HitboxObserver>::notify();
}