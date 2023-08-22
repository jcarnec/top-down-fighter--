#include "MoveCommand.h"

MoveCommand::MoveCommand(Player* player, const glm::vec2& direction, const std::string& name)
    : Command(name), player(player), direction(direction) {}

void MoveCommand::execute() {
    // move in the specified direction
    player->move(direction);

}

