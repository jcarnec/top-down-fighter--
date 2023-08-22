#include "PlayerState.h"
#include "Player.h"
#include <glm/glm.hpp>

void MovingState::move(Player* player, glm::vec2 direction) {
    player->setPosition(player->getPosition() + direction * player->getMoveSpeed());
}

void MovingState::update(Player* player) {
    // Update logic for moving state
}

// Other methods specific to MovingState...
