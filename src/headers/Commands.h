#ifndef COMMANDS_H
#define COMMANDS_H
#include <iostream>
#include "Command.h"
#include "Controllers/Controller.h"
#include "SetModeCommand.h"
#include "SetFileNameCommand.h"
#include "SetPlaceShipCommand.h"

class Commands
{
private:
    Controller* controller;

    Command* set_mode_command;

    Command* set_filename_command;

    Command* set_placeship_command;

public:
    Commands();

    void SetController(Controller* controller);

    void set_mode();

    void set_filename();

    void set_placeship();


    ~Commands();
};

#endif