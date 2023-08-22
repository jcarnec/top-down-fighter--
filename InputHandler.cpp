#include "InputHandler.h"
#include "CommandFactory.h"
#include "Player.h"

InputHandler::InputHandler(Player player) {
    // Initialize keyBindings as needed

    // Example: Bind the Left arrow key to the MoveLeftCommand
    keyBindings[SDLK_LEFT] = [&player]() {
        player.associateCommand(CommandFactory::createMoveLeftCommand(&player));
    };

    // Example: Bind the Right arrow key to the MoveRightCommand
    keyBindings[SDLK_LEFT] = [&player]() {
        player.associateCommand(CommandFactory::createMoveRightCommand(&player));
    };

    // You can add more key bindings here...
}


void InputHandler::handleInput() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_KEYDOWN) {
            const auto it = keyBindings.find(event.key.keysym.sym);
            if (it != keyBindings.end()) {
                it->second();
            }
        }
    }
}

void InputHandler::bindKeyToCommand(SDL_Keycode key, const CommandFunction& commandFunction) {
    keyBindings[key] = commandFunction;
}
