#ifndef COMMANDS_H
#define COMMANDS_H
#include <iostream>
#include "Command.h"
#include "Controllers/Controller.h"
#include "SetModeCommand.h"
#include "SetFileNameCommand.h"

class Commands
{
private:
    Controller* controller;

    Command* set_mode_command;

    Command* set_filename_command;

public:
    Commands();

    void SetController(Controller* controller);

    void set_mode();

    void set_filename();


    ~Commands();
};

#endif