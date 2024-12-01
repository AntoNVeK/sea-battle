#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <iterator>
#include "./headers/Game.h"

#include "./headers/IO/Controller.h"
#include "./headers/Command.h"
#include "./headers/SetModeCommand.h"

#include "./headers/ControllerStartGame.h"
#include "./headers/IO/Printer_Table.h"
#include "./headers/IO/Printer_Message.h"
#include "./headers/IO/ConsoleInputer.h"

//#include "./headers/IO/Controller.h"


using json = nlohmann::json;

void print(Table& table)
{
    CellState state = UNKNOWN;
    const std::vector<std::vector<CellState>>& vec = table.GetCoords();
    const std::set<Coord>& attack_elements = table.GetAttackCoords();
    for(int j = 0; j < table.GetY(); j++)
    {
        for(int i = 0; i < table.GetX(); i++){
            state = vec[j][i];
            if (attack_elements.find(Coord(i + 1, j + 1)) != attack_elements.end())
            {
                
                if (state != SHIP)
                {
                    std::cout << static_cast<char>(state);
                }
                else
                {
                    std::cout << static_cast<char>(table.GetStateSegmentShip(i, j));
                }
            }
            else
            {
                std::cout << static_cast<char>(UNKNOWN);
            }
            std::cout << " ";
        }
        std::cout << "\n";
    }
}

/*
¬ классе игры выбор что делать через соста€ни€
*/


int main()
{

    SetFileNameCommand set_file_name;
    SetModeCommand set_mode;
    SetCoordCommand set_coord;
    SetPlaceShipCommand set_place_ship;


    EndGameCommand end_game;
    
    Game game(set_file_name, set_mode, set_coord, set_place_ship, end_game);
    
    ControllerStartGame controller(game);
    
    set_file_name.SetInput(&controller);
    set_mode.SetInput(&controller);
    set_coord.SetInput(&controller);
    set_place_ship.SetInput(&controller);
    end_game.SetInput(&controller);

    Controller<ConsoleInputer, Printer_Table, Printer_Message> gamecontroller(game);

    gamecontroller.run();

    return 0;

}