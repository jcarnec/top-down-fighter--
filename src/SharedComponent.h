#pragma once
#include <vector>

class Entity;
class SharedComponent {
public:
    SharedComponent() = default;

    SharedComponent(const std::vector<Entity*>& owners) : owners(owners) {}

    const std::vector<Entity*>& getOwners() const { return owners; }

    void addOwner(Entity& owner) {
        owners.push_back(&owner);
    }

private:
    std::vector<Entity*> owners;
};