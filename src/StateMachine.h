/* === StateMachine.h === */
#pragma once

#include <memory>
#include <unordered_map>
#include <string>
#include "SingleComponent.h"

class Player;
class State;

class StateMachine : public SingleComponent {
public:

    StateMachine(Entity& owner) : SingleComponent(owner), currentState(nullptr) {};

    void registerState(const std::string& stateName, std::shared_ptr<State> state);
    void changeState(const std::string& stateName, const std::string& command);
    void update();
    void applyCommand(const std::string& command);
    void setCurrentPlayer(Player* player);
    void draw() const;
    // get state by string
    std::shared_ptr<State> getState(const std::string& stateName) const {
        return states.at(stateName);
    }



private:
    State* currentState;
    Player* currentPlayer;
    std::unordered_map<std::string, std::shared_ptr<State>> states;
};

/* === End of StateMachine.h === */
