#ifndef SET_FILE_NAME_COMMAND_H
#define SET_FILE_NAME_COMMAND_H
#include <iostream>
#include "Command.h"
#include "ControllerStartGame.h"
class SetFileNameCommand
{
private:
    ControllerStartGame* controller;

public:
    SetFileNameCommand();

    void SetInput(ControllerStartGame* controller);

    std::string execute();

    ~SetFileNameCommand() = default;
};

#endif