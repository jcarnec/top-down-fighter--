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
    State(Player* player, std::string name) : player(player), name(name) {}
    virtual void update() = 0;
    virtual void enter(std::string command) = 0; // New method to handle state entry
    virtual void exit() = 0;  // New method to handle state exit //
    virtual void handleInput() = 0;
    virtual void onCommand(std::string command) = 0 ;
    virtual void clearInputList() = 0;
    virtual ~State() = default;

public:
    Player* player;
    std::string name;
};

class StandingState : public State {
public:
    StandingState(Player* player, std::string name) : State(player, name) {}
    void update() override;
    void enter(std::string command) override;
    void exit() override;
    void handleInput() override;
    void onCommand(std::string command) override;
    void clearInputList() override;
};



class MovingState : public State {
public:
    MovingState(Player* player, std::string name) : State(player, name) {}
    void update() override;
    void enter(std::string command) override;
    void exit() override;
    void handleInput() override;
    void onCommand(std::string command) override;
    void clearInputList() override;
};
