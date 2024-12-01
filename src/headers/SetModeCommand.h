#ifndef SET_MODE_COMMAND_H
#define SET_MODE_COMMAND_H
#include <iostream>
#include "Command.h"
#include "IO/Input.h"
#include "GameEnums.h"

class SetModeCommand
{
private:
    Input* input;

public:
    SetModeCommand();

    void SetInput(Input* input);

    int execute();

    ~SetModeCommand() = default;
};

#endif