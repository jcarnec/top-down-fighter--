#include "CommandFactory.h"
#include "MoveCommand.h"


MoveCommand* CommandFactory::createMoveLeftCommand(Player* player) {
    return new MoveLeftCommand(player);
}

MoveCommand* CommandFactory::createMoveRightCommand(Player* player) {
    return new MoveRightCommand(player);
}

MoveCommand* CommandFactory::createMoveUpCommand(Player* player) {
    return new MoveUpCommand(player);
}

MoveCommand* CommandFactory::createMoveDownCommand(Player* player) {
    return new MoveDownCommand(player);
}
