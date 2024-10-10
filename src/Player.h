#pragma once
#include <vector>
#include <string>
#include <memory>
#include "BasicPhysicsComponent.h"
#include <glm/glm.hpp>
#include "State.h"
#include <unordered_map>
#include "Entity.h"
#include "InputHandler.h"
#include "HitboxManager.h"


class Player : public Entity {
public:
    Player(glm::vec2 position, Shape shape, std::shared_ptr<HitboxManager> hm);

    void update(); 
    void draw(); 

};

