#ifndef SET_FILE_NAME_COMMAND_H
#define SET_FILE_NAME_COMMAND_H
#include <iostream>
#include "Command.h"
#include "IO/Input.h"
class SetFileNameCommand
{
private:
    Input* input;

public:
    SetFileNameCommand();

    void SetInput(Input* input);

    std::string execute();

    ~SetFileNameCommand() = default;
};

#endif