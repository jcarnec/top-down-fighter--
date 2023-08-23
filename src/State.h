#pragma once

#include <string>
#include <glm/glm.hpp>
#include <vector>
#include <memory>
#include <unordered_map>
#include <algorithm>

class Player; // Forward declaration of Player class

class State {
public:
    State(Player* player) : player(player) {}
    virtual void update() = 0;
    virtual void enter() = 0; // New method to handle state entry
    virtual void exit() = 0;  // New method to handle state exit //
    virtual void handleInput(std::vector<std::string> inputList) = 0;
    virtual ~State() = default;

public:
    Player* player;
};

class StandingState : public State {
public:
    StandingState(Player* player) : State(player) {}
    void update() override;
    void enter() override;
    void exit() override;
    void handleInput(std::vector<std::string> inputList) override;
};



class MovingState : public State {
public:
    MovingState(Player* player) : State(player) {}
    void update() override;
    void enter() override;
    void exit() override;
    void handleInput(std::vector<std::string> inputList) override;
};
