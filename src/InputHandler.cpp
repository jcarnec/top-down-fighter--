#include "InputHandler.h"
#include <iostream>
#include <cstring>
#include <memory>
#include "Player.h"

InputHandler::InputHandler(Player& player) : player(&player) {
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
            std::string command = binding.second;
            if (command != "") {
                associateInput(command);
            }
        }
    }
}

void InputHandler::initializeKeyBindings() {
    // Create command bindings using the InputFactory
    inputMap["UP"] = 'w';
    inputMap["LEFT"] = 'a';
    inputMap["DOWN"] = 's';
    inputMap["RIGHT"] = 'd';
    inputMap["CROUCH"] = 'j';
    inputMap["DASH"] = 'k';

    memset(keyState, BUTTON_UP, sizeof(keyState));
    keyBindings[inputMap["LEFT"]] = "LEFT";
    keyBindings[inputMap["RIGHT"]] = "RIGHT";
    keyBindings[inputMap["UP"]] = "UP";
    keyBindings[inputMap["DOWN"]] = "DOWN";
    keyBindings[inputMap["CROUCH"]] = "CROUCH";
    keyBindings[inputMap["DASH"]] = "DASH";


}


void InputHandler::associateInput(std::string commandName) {
    // add to command list
    inputList.push_back(commandName);
}

void InputHandler::clearInputList() {
    inputList.clear();
}

void InputHandler::logInputList() {
    // log the address of the inputList
    if(inputList.size() != 0) {
        for (auto &input : inputList) {
            std::cout << input << std::endl;
        }
    }
}
