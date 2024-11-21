#ifndef SET_SKILL_COORD_COMMAND_H
#define SET_SKILL_COORD_COMMAND_H
#include <iostream>
#include "Command.h"
#include "Controllers/Controller.h"
class SetSkillCoordCommand : public Command 
{
private:
    Controller* controller;

public:
    SetSkillCoordCommand();

    void SetController(Controller* controller) override;

    void execute() override;

    ~SetSkillCoordCommand() override = default;
};

#endif