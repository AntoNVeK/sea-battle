#ifndef CONSOLEINPUTER_H
#define CONSOLEINPUTER_H

#include <iostream>
#include <map>
#include <functional>
#include <utility> 
#include "../ManagerShips.h"
#include "../Game.h"
#include "../GameState.h"
#include "input.h"
#include "Commands.h"



class ConsoleInputer
{
    Input input_metod;
    Commands& commands;

public:
    ConsoleInputer(Commands& commands) : commands(commands) {}
    std::string getInput();
    std::string getCommand(const std::string& input);
    std::string getString();
};


#endif