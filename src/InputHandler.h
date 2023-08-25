#pragma once

#include <GL/glut.h>
#include "InputFactory.h"
#include "Player.h"
#include <unordered_map>
#include <functional>

#define BUTTON_UP   0
#define BUTTON_DOWN 1

class InputHandler {
public:
    InputHandler(Player* player);

    void keyboardDown(unsigned char key, int x, int y);
    void keyboardUp(unsigned char key, int x, int y);
    void update();

private:
    Player* player;
    std::unordered_map<unsigned char, RegisteredInput*> keyBindings;
    unsigned char keyState[255];
};
