#ifndef VIEW_H
#define VIEW_H
#include <string>
#include "../game.h"
#include "Commands.h"

template<typename Printer_Table, typename Printer_Message>
class View
{
    Commands& list_commands;
    Printer_Table printer_table;
    Printer_Message printer_message;
    Game& game;
public:
    View(Game &game, Commands& commands) : game(game), printer_message(commands), list_commands(commands) {};

    void solve(std::string command);

    void print_message(std::string string);
};

#include "View.hpp"

#endif