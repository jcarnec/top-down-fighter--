#pragma once

#include "Player.h"
#include "RegisteredInput.h"

// Include other command headers...

class InputFactory {
public:
    static RegisteredInput* createMoveLeftInput(Player* player);
    static RegisteredInput* createMoveRightInput(Player* player);
    static RegisteredInput* createMoveUpInput(Player* player);
    static RegisteredInput* createMoveDownInput(Player* player);

private:
    // Private constructor to prevent instantiation
    InputFactory();
};
