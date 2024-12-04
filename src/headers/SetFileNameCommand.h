#ifndef SET_FILE_NAME_COMMAND_H
#define SET_FILE_NAME_COMMAND_H
#include <iostream>
#include "Command.h"
#include "IController.h"
class SetFileNameCommand
{
private:
    IController* controller;

public:
    SetFileNameCommand();

    void SetController(IController* controller);

    std::string execute();

    ~SetFileNameCommand() = default;
};

#endif