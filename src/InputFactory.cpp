
#include "InputFactory.h"

RegisteredInput* InputFactory::createMoveLeftInput(Player* player) {
    return new RegisteredInput( "LEFT", player);
}

RegisteredInput* InputFactory::createMoveRightInput(Player* player) {
    return new RegisteredInput("RIGHT", player);
}

RegisteredInput* InputFactory::createMoveUpInput(Player* player) {
    return new RegisteredInput("UP", player);
}

RegisteredInput* InputFactory::createMoveDownInput(Player* player) {
    return new RegisteredInput("DOWN", player);
}
