#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <iterator>
#include "./headers/Game.h"
#include "./headers/Controllers/ConsoleController.h"
#include "./headers/Views/ConsoleView.h"
#include "./headers/Command.h"
#include "./headers/SetModeCommand.h"
#include "./headers/Commands.h"

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

    Commands commands;
    
    Game game(commands);
    
    ConsoleController controller(game);
    
    commands.SetController(&controller);
    
    game.play();

    game.next_move();



    return 0;

}