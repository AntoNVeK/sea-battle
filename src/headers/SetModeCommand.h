#ifndef SET_MODE_COMMAND_H
#define SET_MODE_COMMAND_H
#include <iostream>
#include "Command.h"
#include "IController.h"
#include "GameEnums.h"

class SetModeCommand
{
private:
    IController* controller;

public:
    SetModeCommand();

    void SetController(IController* controller);

    int execute();

    ~SetModeCommand() = default;
};

#endif