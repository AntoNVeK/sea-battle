#ifndef SET_NUMBER_MOVE_COMMAND_H
#define SET_NUMBER_MOVE_COMMAND_H
#include <iostream>
#include "Command.h"
#include "Controllers/Controller.h"
class SetNumberMoveCommand : public Command 
{
private:
    Controller* controller;

public:
    SetNumberMoveCommand();

    void SetController(Controller* controller) override;

    void execute() override;

    ~SetNumberMoveCommand() override = default;
};

#endif