#ifndef SET_MODE_END_COMMAND_H
#define SET_MODE_END_COMMAND_H
#include <iostream>
#include "Command.h"
#include "Controllers/Controller.h"
class SetModeEndCommand : public Command 
{
private:
    Controller* controller;

public:
    SetModeEndCommand();

    void SetController(Controller* controller) override;

    void execute() override;

    ~SetModeEndCommand() override = default;
};

#endif