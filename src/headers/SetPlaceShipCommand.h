#ifndef SET_PLACE_SHIP_COMMAND_H
#define SET_PLACE_SHIP_COMMAND_H
#include <iostream>
#include "Command.h"
#include "Controllers/Controller.h"
class SetPlaceShipCommand : public Command 
{
private:
    Controller* controller;

public:
    SetPlaceShipCommand();

    void SetController(Controller* controller) override;

    void execute() override;

    ~SetPlaceShipCommand() override = default;
};

#endif