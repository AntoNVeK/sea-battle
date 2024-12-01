#ifndef SET_COORD_COMMAND_H
#define SET_COORD_COMMAND_H
#include <iostream>
#include "Command.h"
#include "ControllerStartGame.h"
#include "Coord.h"

class SetCoordCommand
{
private:
    ControllerStartGame* controller;

public:
    SetCoordCommand();

    void SetInput(ControllerStartGame* controller);

    Coord execute();

    ~SetCoordCommand() = default;
};

#endif