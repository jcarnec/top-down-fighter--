#ifndef PHYSICS_ENTITY_H
#define PHYSICS_ENTITY_H

#include "Entity.h"
#include "HitboxManager.h"
#include "BasicPhysicsComponent.h"

class PhysicsEntity : public Entity {
public:
    PhysicsEntity(glm::vec2 position, Shape shape, std::shared_ptr<HitboxManager> hitboxManager)
        : Entity(position, shape), physics(std::make_unique<BasicPhysicsComponent>(*this)),
          hitboxManager(hitboxManager) {}

    virtual ~PhysicsEntity() = default;

    virtual void update() = 0;
    virtual void draw() const = 0;

    // getter and setter for physics
    BasicPhysicsComponent& getPhysics() const { return *physics; }
    void setPhysics(std::unique_ptr<BasicPhysicsComponent> physics) { this->physics = std::move(physics); }

    // getter and setter for hitbox manager
    std::shared_ptr<HitboxManager> getHitboxManager() const { return hitboxManager; }
    void setHitboxManager(std::shared_ptr<HitboxManager> hitboxManager) { this->hitboxManager = hitboxManager; }

protected:
    std::unique_ptr<BasicPhysicsComponent> physics;
    std::shared_ptr<HitboxManager> hitboxManager;
};

#endif // PHYSICS_ENTITY_H
