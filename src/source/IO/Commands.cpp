#include "../../headers/IO/Commands.h"

Commands::Commands()
{

    if(std::ifstream file{"../commands.json"})
    {
        json json_object;
        file >> json_object;

        for (const auto& [key, value] : json_object.items()) {
            command_map[key] = value;
            long_commands.push_back(value);
        }

        file.close();
    }
    else
    {
        std::cerr << "Could not open file: commands.json" << "\n";
    }

    
}


std::map<std::string, std::string> Commands::get_command_map()
{
    return command_map;
}



std::vector<std::string> Commands::get_long_commands()
{
    return long_commands;
}