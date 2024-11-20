#ifndef SET_MODE_COMMAND_H
#define SET_MODE_COMMAND_H
#include <iostream>
#include "Command.h"
#include "Controllers/Controller.h"
class SetModeCommand : public Command 
{
private:
    Controller* controller;

public:
    SetModeCommand();

    void SetController(Controller* controller);

    void execute() override;

    ~SetModeCommand() override = default;
};

#endif