#ifndef COMMAND_H
#define COMMAND_H
#include "IO/Input.h"

class Command
{
public:
    virtual void execute() = 0;
    virtual void SetInput(Input* input) = 0;
    virtual ~Command() = 0;
};

#endif