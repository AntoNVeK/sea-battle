#ifndef END_GAME_COMMAND_H
#define END_GAME_COMMAND_H
#include <iostream>
#include "IO/Input.h"
class EndGameCommand
{
private:
    Input* input;

public:
    EndGameCommand();

    void SetInput(Input* input);

    void execute();

    ~EndGameCommand() = default;
};

#endif