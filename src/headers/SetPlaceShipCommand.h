#ifndef SET_PLACE_SHIP_COMMAND_H
#define SET_PLACE_SHIP_COMMAND_H
#include <iostream>
#include "Command.h"
#include "IController.h"
#include <vector>
class SetPlaceShipCommand
{
private:
    IController* controller;

public:
    SetPlaceShipCommand();

    void SetController(IController* controller);

    std::vector<int> execute(int len_ship);

    ~SetPlaceShipCommand() = default;
};

#endif