/* === StateMachine.h === */
#pragma once

#include <memory>
#include <unordered_map>
#include <string>

class Player;
class State;

class StateMachine {
public:
    StateMachine();

    void registerState(const std::string& stateName, std::shared_ptr<State> state);
    void changeState(const std::string& stateName);
    void update();

    void setCurrentPlayer(Player* player);

private:
    State* currentState;
    Player* currentPlayer;
    // states map
    std::unordered_map<std::string, std::shared_ptr<State>> states;
};

/* === End of StateMachine.h === */
