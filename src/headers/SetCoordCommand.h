#ifndef SET_COORD_COMMAND_H
#define SET_COORD_COMMAND_H
#include <iostream>
#include "Command.h"
#include "IController.h"
#include "Coord.h"

class SetCoordCommand
{
private:
    IController* controller;

public:
    SetCoordCommand();

    void SetController(IController* controller);

    Coord execute();

    ~SetCoordCommand() = default;
};

#endif