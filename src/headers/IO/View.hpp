#include "View.h"



template<typename Printer_Table, typename Printer_Message>
void View<Printer_Table, Printer_Message>::solve(std::string command)
{
    if (command == "fields") {
        printer_table.drawGameTable(game);
    } else if (command == "attack_message") {
        printer_message.attackMessage(game);
    } else if (command == "state_my_ships") {
        printer_table.showShips(game, false);
    } else if (command == "state_enemy_ships") {
        printer_table.showShips(game, true);
    } else if (command == "show_enemy_ships") {
        printer_table.showTableShips(game, true);
    } else if (command == "show_my_ships") {
        printer_table.showTableShips(game, false);
    } else if (command == "apply_ability") {
        printer_message.applyAbility(game);
    } else if (command == "next_ability") {
        printer_message.nextAbility(game);
    } else if (command == "help") {
        printer_message.help();
    }
}
