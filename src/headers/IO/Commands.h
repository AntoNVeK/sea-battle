#ifndef COMMANDS_H
#define COMMANDS_H

#include <iostream>
#include <map>
#include <functional>
#include <utility> 
#include "../ManagerShips.h"
#include "../Game.h"
#include "../GameState.h"
#include "input.h"
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <nlohmann/json.hpp> // Используется библиотека JSON для C++

using json = nlohmann::json;



class Commands
{

private:
    std::map<std::string, std::string> command_map;
    std::vector<std::string> long_commands;

public:
    Commands();
    std::map<std::string, std::string> get_command_map();
    std::vector<std::string> get_long_commands();

};


#endif