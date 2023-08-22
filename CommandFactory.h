#pragma once

#include "Player.h"
#include "MoveCommand.h"

// Include other command headers...

class CommandFactory {
public:
    static MoveCommand* createMoveCommand(Player* player, const glm::vec2& direction);
    static MoveLeftCommand* createMoveLeftCommand(Player* player);
    static MoveRightCommand* createMoveRightCommand(Player* player);
    static MoveUpCommand* createMoveUpCommand(Player* player);
    static MoveDownCommand* createMoveDownCommand(Player* player);

private:
    // Private constructor to prevent instantiation
    CommandFactory();
};
