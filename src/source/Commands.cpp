#include "../headers/Commands.h"

Commands::Commands() : controller(nullptr) 
{
    set_mode_command = new SetModeCommand();
    set_filename_command = new SetFileNameCommand();
}



void Commands::SetController(Controller* controller) {
    this->controller = controller;
    set_mode_command->SetController(controller);
    set_filename_command->SetController(controller);
}


Commands::~Commands()
{
    delete set_mode_command;
    delete set_filename_command;
}


void Commands::set_mode()
{
    set_mode_command->execute();
}


void Commands::set_filename()
{
    set_filename_command->execute();
}