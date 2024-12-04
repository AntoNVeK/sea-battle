#ifndef COMMAND_H
#define COMMAND_H
#include "IController.h"

class Command
{
public:
    virtual void execute() = 0;
    virtual void SetController(IController* controller) = 0;
    virtual ~Command() = 0;
};

#endif