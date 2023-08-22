#pragma once

#include "Player.h"
#include "MoveCommand.h"

// Include other command headers...

class CommandFactory {
public:
    static MoveCommand* createMoveLeftCommand(Player* player);
    static MoveCommand* createMoveRightCommand(Player* player);
    static MoveCommand* createMoveUpCommand(Player* player);
    static MoveCommand* createMoveDownCommand(Player* player);

private:
    // Private constructor to prevent instantiation
    CommandFactory();
};
