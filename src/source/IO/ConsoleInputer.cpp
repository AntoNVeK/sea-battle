#include "../../headers/IO/ConsoleInputer.h"


std::string ConsoleInputer::getInput()
{
    bool valid_command = false;
    std::string command = "";



    while (!valid_command)
    {
        std::string input = getString();
        if (input != "")
        {
            try
            {
                command = getCommand(input);
                valid_command = true;
            }
            catch(const std::invalid_argument& e)
            {
                std::cerr << e.what()  << '\n';
                std::cerr << "Please try again." << std::endl;
            }
        }
        
    }
    return command;
}

std::string ConsoleInputer::getCommand(const std::string& input)
{

    for (auto command : commands.get_long_commands())
    {
        if (input == command)
            return input;
    }


    for (auto command : commands.get_command_map())
    {
        if (input == command.first)
            return commands.get_command_map()[input];

    }
    
    throw std::invalid_argument("Unknown command: " + input);
}


std::string ConsoleInputer::getString()
{
    std::string input = input_metod.input();

    return input;
}