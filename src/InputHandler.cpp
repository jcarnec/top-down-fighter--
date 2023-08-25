#include "InputHandler.h"
#include <iostream>
#include <cstring>
#include "InputFactory.h"
#include <memory>

InputHandler::InputHandler(Player* player) : player(player) {
    // Clear key state
    memset(keyState, BUTTON_UP, sizeof(keyState));

    // Create command bindings using the InputFactory
    keyBindings[player->inputMap["LEFT"]] = InputFactory::createMoveLeftInput(player);
    keyBindings[player->inputMap["RIGHT"]] = InputFactory::createMoveRightInput(player);
    keyBindings[player->inputMap["UP"]] = InputFactory::createMoveUpInput(player);
    keyBindings[player->inputMap["DOWN"]] = InputFactory::createMoveDownInput(player);
}

void InputHandler::keyboardDown(unsigned char key, int x, int y) {
    keyState[key] = BUTTON_DOWN;
}

void InputHandler::keyboardUp(unsigned char key, int x, int y) {
    keyState[key] = BUTTON_UP;
}

void InputHandler::update() {
    for (auto &binding : keyBindings) {
        if (keyState[binding.first] == BUTTON_DOWN) {
            RegisteredInput* command = binding.second;
            if (command) {
                command->registerInput();
                // log current frame's input to console
                std::cout << "Input: " << std::endl;
            }
        }
    }
}
