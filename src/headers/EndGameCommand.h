#ifndef END_GAME_COMMAND_H
#define END_GAME_COMMAND_H
#include <iostream>
#include "Command.h"
#include "Controllers/Controller.h"
class EndGameCommand : public Command 
{
private:
    Controller* controller;

public:
    EndGameCommand();

    void SetController(Controller* controller) override;

    void execute() override;

    ~EndGameCommand() override = default;
};

#endif