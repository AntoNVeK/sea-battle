#include "../../headers/IO/Commands.h"

Commands::Commands()
{
    command_map["a"] = "attack";
    command_map["ms"] = "state_my_ships";
    command_map["es"] = "state_enemy_ships";
    command_map["q"] = "end";
    command_map["se"] = "show_enemy_ships";
    command_map["sm"] = "show_my_ships";
    command_map["smt"] = "show_my_table";
    command_map["set"] = "show_enemy_table";
    command_map["t"] = "tables";
    command_map["n"] = "next_skill";
    command_map["s"] = "save_game";
    command_map["l"] = "load_game";
    command_map["u"] = "use_skill";
    command_map["h"] = "help";





    long_commands = {
        "attack",
        "state_my_ships",
        "state_enemy_ships",
        "end",
        "show_enemy_ships",
        "show_my_ships",
        "show_my_table",
        "show_enemy_table",
        "tables",
        "next_skill",
        "save_game",
        "load_game",
        "use_skill",
        "help"
    };
}


std::map<std::string, std::string> Commands::get_command_map()
{
    return command_map;
}



std::vector<std::string> Commands::get_long_commands()
{
    return long_commands;
}