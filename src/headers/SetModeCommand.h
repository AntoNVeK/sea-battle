#ifndef SET_MODE_COMMAND_H
#define SET_MODE_COMMAND_H
#include <iostream>
#include "Command.h"
#include "ControllerStartGame.h"
#include "GameEnums.h"

class SetModeCommand
{
private:
    ControllerStartGame* controller;

public:
    SetModeCommand();

    void SetInput(ControllerStartGame* controller);

    int execute();

    ~SetModeCommand() = default;
};

#endif