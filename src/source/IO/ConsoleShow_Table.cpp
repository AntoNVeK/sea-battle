#include "../../headers/IO/ConsoleShow_Table.h"


void ConsoleShow_Table::showTable(Table& table, bool flag)
{
    std::cout << "\n";
    if (flag)
        std::cout << "Player\n";
    else
        std::cout << "Enemy\n";
    CellState state = UNKNOWN;
    const std::vector<std::vector<CellState>>& vec = table.GetCoords();
    const std::set<Coord>& attack_elements = table.GetAttackCoords();
    for(int j = 0; j < table.GetY(); j++)
    {
        for(int i = 0; i < table.GetX(); i++){
            state = vec[j][i];
            if (flag || attack_elements.find(Coord(i + 1, j + 1)) != attack_elements.end())
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




void ConsoleShow_Table::showShips(ManagerShips& ship_manager)
{
    std::cout << std::endl;
    std::cout << "Current states of the ships: " << std::endl;
    for (int j = 0; j < ship_manager.GetCountShips(); j++)
    {
        Ship ship = ship_manager[j];
        std::cout << "Ship at index: " << j << std::endl;
        if (ship.GetOrientation() == VERTICAL)
        {
            for (int i = 0; i < ship.GetLen(); i++)
            {

                std::cout << static_cast<char>(ship.GetSegments()[i]) << "\n";
   
            }
            std::cout << "\n";
        }
        else if (ship.GetOrientation() == HORIZONTAL)
        {
            for (int i = 0; i < ship.GetLen(); i++)
            {
                std::cout << static_cast<char>(ship.GetSegments()[i]) << " ";
            }
            std::cout << "\n";
        }
    }
}