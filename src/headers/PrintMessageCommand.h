#ifndef PRINT_MESSAGE_COMMAND_H
#define PRINT_MESSAGE_COMMAND_H
#include <iostream>
#include "Command.h"
#include "IController.h"
#include "Coord.h"
#include <string>

class PrintMessageCommand
{
private:
    IController* controller;

public:
    PrintMessageCommand();

    void SetController(IController* controller);

    void execute(std::string string);

    ~PrintMessageCommand() = default;
};

#endif