#include "View.h"



template<typename Printer_Table, typename Printer_Message>
void View<Printer_Table, Printer_Message>::solve(std::string command)
{
    if (command == "tables") {
        printer_table.drawGameTable(game);
    } else if (command == "attack_message") {
        printer_message.attackMessage(game);
    } else if (command == "state_my_ships") {
        printer_table.showShips(game, true);
    } else if (command == "state_enemy_ships") {
        printer_table.showShips(game, false);
    } else if (command == "show_enemy_ships") {
        printer_table.showTableShips(game, false);
    } else if (command == "show_my_ships") {
        printer_table.showTableShips(game, true);
    } else if (command == "show_my_table") {
        printer_table.showTable(game, true);
    } else if (command == "show_enemy_table") {
        printer_table.showTable(game, false);
    } else if (command == "use_skill") {
        printer_message.useSkill(game);
    } else if (command == "next_skill") {
        printer_message.nextSkill(game);
    } else if (command == "help") {
        printer_message.help();
    }
}


template<typename Printer_Table, typename Printer_Message>
void View<Printer_Table, Printer_Message>::print_message(std::string string)
{
    printer_message.print_message(string);
}