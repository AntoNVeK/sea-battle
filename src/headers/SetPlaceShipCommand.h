#ifndef SET_PLACE_SHIP_COMMAND_H
#define SET_PLACE_SHIP_COMMAND_H
#include <iostream>
#include "Command.h"
#include "IO/Input.h"
#include <vector>
class SetPlaceShipCommand
{
private:
    Input* input;

public:
    SetPlaceShipCommand();

    void SetInput(Input* input);

    std::vector<int> execute(int len_ship);

    ~SetPlaceShipCommand() = default;
};

#endif