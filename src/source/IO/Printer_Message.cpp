#include "../../headers/IO/Printer_Message.h"




void Printer_Message::nextAbility(Game &game)
{


    switch (game.get_name_next_skill())
    {
        case SkillName::Attack:
            printer.print("Next skill is Attack");
            break;
        case SkillName::DoubleAttack:
            printer.print("Next skill is DoubleAttack");
            break;
        case SkillName::Scanner:
            printer.print("Next skill is Scanner");
            break;
        case SkillName::UNKNOWN:
            printer.print("No abilities");
            break;
    }
}

void Printer_Message::applyAbility(Game& game)
{


    switch (game.get_name_next_skill())
    {
        case SkillName::Attack:
            printer.print("Using Attack...");
            break;
        case SkillName::DoubleAttack:
            printer.print("Using DoubleAttack...");
            break;
        case SkillName::Scanner:
            printer.print("Using Scanner...");
            break;
        case SkillName::UNKNOWN:
            printer.print("No abilities");
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
                printer.print("You hit!");
            else
                printer.print("You miss");
            break;
        }
        case Player::Bot:
        {
            if (result)
                printer.print("Bot hit!");
            else
                printer.print("Bot miss");
            break;
        }
            
    }

}

void Printer_Message::help()
{
    for (auto mes : commands.get_command_map())
    {
        printer.print(mes.first + " - " + mes.second);
    }
}