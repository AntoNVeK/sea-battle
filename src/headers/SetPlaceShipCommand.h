#ifndef SET_PLACE_SHIP_COMMAND_H
#define SET_PLACE_SHIP_COMMAND_H
#include <iostream>
#include "Command.h"
#include "ControllerStartGame.h"
#include <vector>
class SetPlaceShipCommand
{
private:
    ControllerStartGame* controller;

public:
    SetPlaceShipCommand();

    void SetInput(ControllerStartGame* controller);

    std::vector<int> execute(int len_ship);

    ~SetPlaceShipCommand() = default;
};

#endif