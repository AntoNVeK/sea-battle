#ifndef COMMANDS_H
#define COMMANDS_H
#include <iostream>
#include "Command.h"
#include "Controllers/Controller.h"
#include "SetModeCommand.h"
#include "SetFileNameCommand.h"
#include "SetPlaceShipCommand.h"
#include "SetNumberMoveCommand.h"
#include "SetPlayerAttackCommand.h"
#include "SetSkillCoordCommand.h"
#include "SetModeEndCommand.h"

class Commands
{
private:
    Controller* controller;

    Command* set_mode_command;

    Command* set_filename_command;

    Command* set_placeship_command;

    Command* set_numbermove_command;

    Command* set_playerattack_command;

    Command* set_skillcoord_command;

    Command* set_modeend_command;

public:
    Commands();

    void SetController(Controller* controller);

    void set_mode();

    void set_filename();

    void set_placeship();

    void set_numbermove();

    void set_playerattackmove();

    void set_skillcoord();

    void set_modeend();

    ~Commands();
};

#endif