#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <iostream>
#include <map>
#include <functional>
#include "ConsoleShow.h"
// #include "../renderer-elements/game_message.h"
#include "../GameState.h"
#include "../Table.h"
#include "Printer_Table.h"
#include "View.h"
#include "../Game.h"

template<typename Input, typename Printer_Table, typename Printer_Message>
class GameController {
private:
    Game &game;
    Input& input;
    RendererTracker<Printer_Table, Printer_Message> renderer_tracker;
    std::map<std::string, std::function<void()>> commands;

public:
    GameController(Game &game, Input& input ) : game(game), renderer_tracker(game) { initialize_commands(); }
    
    void initialize_commands();
    
    void run();
};

#include "Controller.hpp"

#endif 