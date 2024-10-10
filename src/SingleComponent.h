#pragma once
#include "Entity.h"

class Entity;
class SingleComponent {
public:
    SingleComponent(Entity& owner) : owner(&owner) {}

    virtual ~SingleComponent() = default;

    Entity* getOwner() const { return owner; }

protected:
    Entity* owner;
};