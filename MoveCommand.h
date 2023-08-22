#pragma once

#include "Command.h"
#include "Player.h"
#include <glm/glm.hpp>

class MoveCommand : public Command {
public:
    MoveCommand(Player* player, const glm::vec2& direction);

    void execute() override;

private:
    Player* player;
    glm::vec2 direction;
};


class MoveLeftCommand : public Command {
public:
    MoveLeftCommand(Player* player);

    void execute() override;
};

class MoveRightCommand : public Command {
public:
    MoveRightCommand(Player* player);

    void execute() override;
};

class MoveUpCommand : public Command {
public:
    MoveUpCommand(Player* player);

    void execute() override;
};

class MoveDownCommand : public Command {
public:
    MoveDownCommand(Player* player);

    void execute() override;
};


