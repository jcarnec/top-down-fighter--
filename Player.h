#ifndef PLAYER_H
#define PLAYER_H

#include <glm/glm.hpp>
#include "PlayerState.h"
#include "Command.h"

class Player {
public:
    Player(glm::vec2 position, float radius);

    void move(glm::vec2 direction);
    void update(); // Call to update player state
    void draw() const;

    void setState(PlayerState* newState);

    // Getter and setter methods for attributes
    glm::vec2 getPosition() const;
    void setPosition(glm::vec2 newPosition);

    float getRadius() const;
    void setRadius(float newRadius);

    float getMoveSpeed() const;
    void setMoveSpeed(float speed);

    PlayerState* getCurrentState() const;
    void setCurrentState(PlayerState* newState);

    // Add a method to associate a command with a key
    void associateCommand(Command* command);

    // Execute a command associated with a key
    void executeCommand(const std::string& key);


public: 
    // Other public methods or members as needed
    std::unordered_map<std::string, Command*> commandMap; // Use an unordered_map to store commands

private:
    glm::vec2 position;
    float radius;
    float moveSpeed;
    PlayerState* currentState;
};

#endif // PLAYER_H
