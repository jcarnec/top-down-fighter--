#pragma once

#include <string>
#include "Player.h"


class RegisteredInput {

public:
    RegisteredInput(const std::string name, Player* player) ;
    
    // Default implementation for registerInput
    virtual void registerInput() {
        // Default behavior
        if (player) {
            player->associateInput(name);
        }
    }
    
    virtual ~RegisteredInput() = default;

public:
    std::string name;
    Player* player;

};

