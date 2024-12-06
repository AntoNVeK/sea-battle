#include "../../headers/IO/Printer_Table.h"

void Printer_Table::drawGameTable(Game &game)
{

    



    Table& player_table = game.get_player_table();
    
    Table& enemy_table = game.get_enemy_table();

    show.showTable(player_table, true);
    
    show.showTable(enemy_table, false);
    
    

}
void Printer_Table::showShips(Game &game, bool flag)
{


    if (flag)
        show.showShips(game.get_player_ships());
    else
        show.showShips(game.get_enemy_ships());
    
}
void Printer_Table::showTableShips(Game &game, bool flag)
{


    if (flag)
    {
        show.showTable(game.get_player_table(), flag);
        show.showShips(game.get_player_ships());
    }
    else
    {
        show.showTable(game.get_enemy_table(), flag);
        show.showShips(game.get_enemy_ships());
    }
}


void Printer_Table::showTable(Game &game, bool flag)
{
    
    show.showTable(game.get_player_table(), flag);
}