#include "CommandFactory.h"

MoveCommand* CommandFactory::createMoveCommand(Player* player, const glm::vec2& direction) {
    return new MoveCommand(player, direction);
}

MoveLeftCommand* CommandFactory::createMoveLeftCommand(Player* player) {
    return new MoveLeftCommand(player);
}

MoveRightCommand* CommandFactory::createMoveRightCommand(Player* player) {
    return new MoveRightCommand(player);
}

MoveUpCommand* CommandFactory::createMoveUpCommand(Player* player) {
    return new MoveUpCommand(player);
}

MoveDownCommand* CommandFactory::createMoveDownCommand(Player* player) {
    return new MoveDownCommand(player);
}
