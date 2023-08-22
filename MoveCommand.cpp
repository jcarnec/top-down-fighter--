#include "Command.h"
#include "Player.h"

class MoveCommand : public Command {
public:
    MoveCommand(const std::string& name, Player* player, glm::vec2 direction)
        : Command(name), player(player), direction(direction) {}

    void execute() override {
        // move in the specified direction
        player->move(direction);
    }

private:
    Player* player;
    glm::vec2 direction;
};

class MoveLeftCommand : public MoveCommand {
public:
    MoveLeftCommand(Player* player)
        : MoveCommand("Move Left", player, glm::vec2(-1.0f, 0.0f)) {}
};

class MoveRightCommand : public MoveCommand {
public:
    MoveRightCommand(Player* player)
        : MoveCommand("Move Right", player, glm::vec2(1.0f, 0.0f)) {}
};

class MoveUpCommand : public MoveCommand {
public:
    MoveUpCommand(Player* player)
        : MoveCommand("Move Up", player, glm::vec2(0.0f, 1.0f)) {}
};

class MoveDownCommand : public MoveCommand {
public:
    MoveDownCommand(Player* player)
        : MoveCommand("Move Down", player, glm::vec2(0.0f, -1.0f)) {}
};
