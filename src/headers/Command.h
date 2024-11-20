#ifndef COMMAND_H
#define COMMAND_H
#include "Controllers/Controller.h"

class Command
{
public:
    virtual void execute() = 0;
    virtual void SetController(Controller* controller) = 0;
    virtual ~Command() = 0;
};

#endif