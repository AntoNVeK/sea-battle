#ifndef SET_COORD_COMMAND_H
#define SET_COORD_COMMAND_H
#include <iostream>
#include "Command.h"
#include "IO/Input.h"
#include "Coord.h"

class SetCoordCommand
{
private:
    Input* input;

public:
    SetCoordCommand();

    void SetInput(Input* input);

    Coord execute();

    ~SetCoordCommand() = default;
};

#endif