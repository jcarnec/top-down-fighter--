#pragma once

#include <GL/glut.h>
#include "InputFactory.h"
#include "Player.h"
#include <unordered_map>
#include <functional>

class InputHandler {
public:
    InputHandler(Player* player);

    void keyboard(unsigned char key, int x, int y);

private:
    Player* player;
    std::unordered_map<unsigned char, RegisteredInput*> keyBindings;
};

