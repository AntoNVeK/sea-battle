#ifndef COMMAND_H
#define COMMAND_H
#include "ControllerStartGame.h"

class Command
{
public:
    virtual void execute() = 0;
    virtual void SetInput(ControllerStartGame* controller) = 0;
    virtual ~Command() = 0;
};

#endif