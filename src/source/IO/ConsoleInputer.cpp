#include "../../headers/IO/ConsoleInputer.h"


std::string ConsoleInputer::getInput()
{
    bool valid_command = false;
    std::string command = "";
    while (!valid_command)
    {
        std::cout << "Enter command: ";
        std::string input = input_metod.input();

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
    return command;
}

std::string ConsoleInputer::getCommand(const std::string& input)
{

    if (std::find(commands.get_long_commands().begin(), commands.get_long_commands().end(), input) != commands.get_long_commands().end())
    {
        return input;
    }


    if(commands.get_command_map().find(input) == commands.get_command_map().end())
    {
        throw std::invalid_argument("Unknown command: " + input);
    }
    return commands.get_command_map()[input];
}