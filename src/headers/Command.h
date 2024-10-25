#ifndef COMMAND_H
#define COMMAND_H

#include "Coord.h"

class Command
{
public:
    virtual Coord get_coord() = 0;

    virtual ~Command() = 0;
};



#endif