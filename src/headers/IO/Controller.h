#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <iostream>
#include <map>
#include <functional>
#include "ConsoleShow_Table.h"
#include "Printer_Message.h"
#include "../GameState.h"
#include "../Table.h"
#include "Printer_Table.h"
#include "View.h"
#include "../Game.h"
#include "Commands.h"

template<typename Inputer, typename Printer_Table, typename Printer_Message>
class Controller {
private:
    Commands list_commands;
    Game &game;
    Inputer inputer;
    View<Printer_Table, Printer_Message> view;
    std::map<std::string, std::function<void()>> commands;

public:
    Controller(Game &game) : game(game), inputer(list_commands), view(game, list_commands) { initialize_commands(); }
    
    void initialize_commands();
    
    void run();
};

#include "Controller.hpp"

#endif 