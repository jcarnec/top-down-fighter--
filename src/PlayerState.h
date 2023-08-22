#ifndef PLAYERSTATE_H
#define PLAYERSTATE_H

#include <glm/glm.hpp>

class Player; // Forward declaration of Player class

class PlayerState {
public:
    virtual void move(Player* player, glm::vec2 direction) = 0;
    virtual void update(Player* player) = 0;
    virtual ~PlayerState() = default;
};

class StandingState : public PlayerState {
public:
    void move(Player* player, glm::vec2 direction) override;
    void update(Player* player) override;
};

class MovingState : public PlayerState {
public:
    void move(Player* player, glm::vec2 direction) override;
    void update(Player* player) override;
};

#endif // PLAYERSTATE_H
