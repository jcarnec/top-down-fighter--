#include "Player.h"
#include "RegisteredInput.h"

// You might not need to include Player.h here if it's already included in RegisteredInput.h
// #include "Player.h"

// Constructor initializes the name and associated player
RegisteredInput::RegisteredInput(const std::string name, Player* player) : name(name), player(player) {}

