#pragma once

#include <functional>
#include <unordered_map>
#include <SDL2/SDL.h> // Assuming you're using SDL for input handling
#include "Player.h"

class InputHandler {
public:
    using CommandFunction = std::function<void()>;

    InputHandler(Player player);

    InputHandler(player);

    void handleInput();

    void bindKeyToCommand(SDL_Keycode key, const CommandFunction& commandFunction);

private:
    std::unordered_map<SDL_Keycode, CommandFunction> keyBindings;
    // player
    


};
