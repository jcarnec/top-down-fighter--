#pragma once

#include <string>
#include <glm/glm.hpp>
#include <vector>
#include <memory>
#include <unordered_map>
#include <algorithm>
#include <GL/glut.h>
#include <cmath>
#include "HitboxCollection.h"
#include "HitboxObserverCollection.h"

class Player; // Forward declaration of Player class

class State
{
public:
    State(Player *player, std::string name) : player(player), name(name) {}
    void draw();
    void physicsUpdate();
    virtual void update() = 0;
    virtual void enter(std::string command) = 0; // New method to handle state entry
    virtual void createBoxes() = 0;              // New method to handle state entry
    virtual void deleteBoxes() = 0;              // New method to handle state entry
    virtual void updateBoxes() = 0;              // New method to handle state entry
    virtual void exit() = 0;                     // New method to handle state exit //
    virtual void handleInput() = 0;
    virtual void onCommand(std::string command) = 0;
    virtual ~State() = default;
    Player *player;
    std::string name;
    int stateFrameCount = 0;
    const int DURATION = 0;
    // a hitbox collection component unique pointer to each state
    std::unique_ptr<HitboxCollection> hitboxCollection;
    HitboxCollection *getHitboxCollection() { return hitboxCollection.get(); }
    void setHitboxCollection(std::unique_ptr<HitboxCollection> hc)
    {
        hitboxCollection = std::move(hc);
    }

    // a hurtbox collection component unique pointer to each state
    std::unique_ptr<HitboxObserverCollection> hitboxObserverCollection;

    HitboxObserverCollection *getHitboxObserverCollection()
    {
        return hitboxObserverCollection.get();
    }

    void setHitboxObserverCollection(std::unique_ptr<HitboxObserverCollection> hoc) { hitboxObserverCollection = std::move(hoc); }
};

// Standing
class StandingState : public State
{
public:
    StandingState(Player *player, std::string name) : State(player, name) {}
    void update() override;
    void enter(std::string command) override;
    void exit() override;
    void handleInput() override;
    void createBoxes() override;
    void deleteBoxes() override;
    void updateBoxes() override;
    void onCommand(std::string command) override;
};

// Moving
class MovingState : public State
{
public:
    MovingState(Player *player, std::string name) : State(player, name) {}
    void update() override;
    void enter(std::string command) override;
    void exit() override;
    void handleInput() override;
    void createBoxes() override;
    void deleteBoxes() override;
    void updateBoxes() override;
    void onCommand(std::string command) override;

protected:
    glm::vec2 directionOfMovement = glm::vec2(0.0f, 0.0f);
};

// Crouching
class CrouchingState : public State
{
public:
    CrouchingState(Player *player, std::string name) : State(player, name) {}
    void update() override;
    void enter(std::string command) override;
    void exit() override;
    void handleInput() override;
    void createBoxes() override;
    void deleteBoxes() override;
    void updateBoxes() override;
    void onCommand(std::string command) override;

protected:
    glm::vec2 directionOfMovement = glm::vec2(0.0f, 0.0f);
    const float crouchingStateFriction = 0.5f;
    const float crouchingStateMoveForceMultiplier = 0.5f;
    const float crouchingStateMaxSpeedMultiplier = 0.25f;
};

// Dashing
class DashingState : public State
{
public:
    DashingState(Player *player, std::string name) : State(player, name) {}
    void update() override;
    void enter(std::string command) override;
    void exit() override;
    void handleInput() override;
    void createBoxes() override;
    void deleteBoxes() override;
    void updateBoxes() override;
    void onCommand(std::string command) override;

protected:
    glm::vec2 directionOfMovement = glm::vec2(0.0f, 0.0f);
    float dashForce = 50.0f;
    const int DURATION = 20;
};
