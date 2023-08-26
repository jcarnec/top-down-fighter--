#pragma once

#include <GL/glut.h>
#include <unordered_map>
#include <functional>
#include <string>
#include <memory>
#include <vector>


class Player;

#define BUTTON_UP   0
#define BUTTON_DOWN 1



class InputHandler {
public:
    InputHandler(Player& player);

    void keyboardDown(unsigned char key, int x, int y);
    void keyboardUp(unsigned char key, int x, int y);
    void update();

    // getter and setter input list
    std::vector<std::string> getInputList() { return inputList;}
    void setInputList(std::vector<std::string> inputList) { this->inputList = inputList; }

    // clear input list
    void clearInputList();

    void initializeKeyBindings();

    void associateInput(std::string commandName);

    void logInputList();
protected:
    Player* player;
    std::unordered_map<std::string, unsigned char> inputMap = {};
    std::vector<std::string> inputList = {};

private:
    std::unordered_map<unsigned char, std::string> keyBindings = {};
    unsigned char keyState[255];
};
