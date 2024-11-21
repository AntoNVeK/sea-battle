#include "../headers/Commands.h"

Commands::Commands() : controller(nullptr) 
{
    set_mode_command = new SetModeCommand();
    set_filename_command = new SetFileNameCommand();
    set_placeship_command = new SetPlaceShipCommand();
    set_numbermove_command = new SetNumberMoveCommand();
    set_playerattack_command = new SetPlayerAttackCommand();
    set_skillcoord_command = new SetSkillCoordCommand();
    set_modeend_command = new SetModeEndCommand();
    endgame_command = new EndGameCommand();
}



void Commands::SetController(Controller* controller) {
    this->controller = controller;
    set_mode_command->SetController(controller);
    set_filename_command->SetController(controller);
    set_placeship_command->SetController(controller);
    set_numbermove_command->SetController(controller);
    set_playerattack_command->SetController(controller);
    set_skillcoord_command->SetController(controller);
    set_modeend_command->SetController(controller);
    endgame_command->SetController(controller);
}


Commands::~Commands()
{

}


void Commands::set_mode()
{
    set_mode_command->execute();
}


void Commands::set_filename()
{
    set_filename_command->execute();
}

void Commands::set_placeship()
{
    set_placeship_command->execute();
}

void Commands::set_numbermove()
{
    set_numbermove_command->execute();
}


void Commands::set_playerattackmove()
{
    set_playerattack_command->execute();
}

void Commands::set_skillcoord()
{
    set_skillcoord_command->execute();
}


void Commands::set_modeend()
{
    set_modeend_command->execute();
}

void Commands::endgame()
{
    endgame_command->execute();
}