#ifndef END_GAME_COMMAND_H
#define END_GAME_COMMAND_H
#include <iostream>
#include "ControllerStartGame.h"
class EndGameCommand
{
private:
    ControllerStartGame* controller;

public:
    EndGameCommand();

    void SetInput(ControllerStartGame* controller);

    void execute();

    ~EndGameCommand() = default;
};

#endif