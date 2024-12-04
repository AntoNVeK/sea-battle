#ifndef END_GAME_COMMAND_H
#define END_GAME_COMMAND_H
#include <iostream>
#include "IController.h"
class EndGameCommand
{
private:
    IController* controller;

public:
    EndGameCommand();

    void SetController(IController* controller);

    void execute();

    ~EndGameCommand() = default;
};

#endif