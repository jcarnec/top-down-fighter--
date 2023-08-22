#pragma once

#include "Command.h"
#include "Player.h"
#include <glm/glm.hpp>

class MoveCommand : public Command {
public:
    MoveCommand(Player* player, const glm::vec2& direction, const std::string& name);

    void execute() override;

private:
    Player* player;
    glm::vec2 direction;
};


class MoveLeftCommand : public MoveCommand {    
public:
    MoveLeftCommand(Player* player)
        : MoveCommand(player, glm::vec2(-1.0f, 0.0f), "Move Left") {
    }
};

class MoveRightCommand : public MoveCommand {
public:
    MoveRightCommand(Player* player)
        : MoveCommand(player, glm::vec2(1.0f, 0.0f), "Move Right") {
    }
};

class MoveUpCommand : public MoveCommand {
public:
    MoveUpCommand(Player* player)
        : MoveCommand(player, glm::vec2(0.0f, 1.0f), "Move Up") {
    }
};

class MoveDownCommand : public MoveCommand {
public:
    MoveDownCommand(Player* player)
        : MoveCommand(player, glm::vec2(0.0f, -1.0f), "Move Down") {
    }
};

