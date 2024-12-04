#include "../../headers/IO/Printer_Message.h"




void Printer_Message::nextSkill(Game &game)
{
    printer.print(std::to_string(game.get_name_next_skill()) + "\n");
}

void Printer_Message::useSkill(Game& game)
{


    switch (game.get_name_next_skill())
    {
        case SkillName::Attack:
            printer.print("Using Attack...\n");
            break;
        case SkillName::DoubleAttack:
            printer.print("Using DoubleAttack...\n");
            break;
        case SkillName::Scanner:
            printer.print("Using Scanner...\n");
            break;
        case SkillName::UNKNOWN:
            printer.print("No abilities\n");
            break;
    }
}



void Printer_Message::attackMessage(Game& game)
{

    bool result = game.get_result_attack();
    Player player = game.get_current_player();

    switch (player)
    {
        case Player::User:
        {
            if (result)
                printer.print("You hit!\n");
            else
                printer.print("You miss\n");
            break;
        }
        case Player::Bot:
        {
            if (result)
                printer.print("Bot hit!\n");
            else
                printer.print("Bot miss\n");
            break;
        }
            
    }

}

void Printer_Message::help()
{
    for (auto mes : commands.get_command_map())
    {
        printer.print(mes.first + " - " + mes.second + "\n");
    }
}


void Printer_Message::print_message(std::string message)
{
    printer.print(message);
}