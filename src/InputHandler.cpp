/* === InputHandler.cpp === */
#include "InputHandler.h"

InputHandler::InputHandler(Player* player) : player(player) {
    // Create command bindings using the InputFactory
    keyBindings[player->inputMap["LEFT"]] = InputFactory::createMoveLeftInput(player);
    keyBindings[player->inputMap["RIGHT"]] = InputFactory::createMoveRightInput(player);
    keyBindings[player->inputMap["UP"]] = InputFactory::createMoveUpInput(player);
    keyBindings[player->inputMap["DOWN"]] = InputFactory::createMoveDownInput(player);
}

void InputHandler::keyboard(unsigned char key, int x, int y) {
    auto it = keyBindings.find(key);
    if (it != keyBindings.end()) {
        RegisteredInput* command = it->second;
        if (command) {
            command->registerInput();
        }
    }
}

/* === End of InputHandler.cpp === */