#ifndef SET_FILE_NAME_COMMAND_H
#define SET_FILE_NAME_COMMAND_H
#include <iostream>
#include "Command.h"
#include "Controllers/Controller.h"
class SetFileNameCommand : public Command 
{
private:
    Controller* controller;

public:
    SetFileNameCommand();

    void SetController(Controller* controller) override;

    void execute() override;

    ~SetFileNameCommand() override = default;
};

#endif