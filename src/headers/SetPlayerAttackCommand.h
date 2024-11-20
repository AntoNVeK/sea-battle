#ifndef SET_PLAYER_ATTACK_COMMAND_H
#define SET_PLAYER_ATTACK_COMMAND_H
#include <iostream>
#include "Command.h"
#include "Controllers/Controller.h"
class SetPlayerAttackCommand : public Command 
{
private:
    Controller* controller;

public:
    SetPlayerAttackCommand();

    void SetController(Controller* controller) override;

    void execute() override;

    ~SetPlayerAttackCommand() override = default;
};

#endif