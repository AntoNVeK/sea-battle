#include "../../headers/IO/ConsoleShow_Table.h"




void ConsoleShow_Table::showTable(Table& table, bool flag)
{
    printer.print("\n");
    if (flag)
        printer.print("Player\n");
    else
        printer.print("Enemy\n");

    
    printer.print("   ");
    for (int i = 1; i <= table.GetX(); ++i) {
        printer.print(std::to_string(i) + " ");
    }
    printer.print("\n");

    CellState state = UNKNOWN;
    const std::vector<std::vector<CellState>>& vec = table.GetCoords();
    const std::set<Coord>& attack_elements = table.GetAttackCoords();
    for (int j = 0; j < table.GetY(); j++)
    {
        
        std::cout << std::setw(2) << std::right << j + 1 << " ";

        for (int i = 0; i < table.GetX(); i++) {
            state = vec[j][i];
            if (flag || attack_elements.find(Coord(i + 1, j + 1)) != attack_elements.end())
            {
                if (state != SHIP)
                {
                    char ch = static_cast<char>(state);
                    std::string str(1, ch);
                    printer.print(str);
                }
                else
                {
                    char ch = static_cast<char>(table.GetStateSegmentShip(i, j));
                    std::string str(1, ch);
                    printer.print(str);
                }
            }
            else
            {
                char ch = static_cast<char>(UNKNOWN);
                std::string str(1, ch);
                printer.print(str);
            }
            printer.print(" ");
        }
        printer.print("\n");
    }
    printer.print("\n");
}




void ConsoleShow_Table::showShips(ManagerShips& ship_manager)
{
    printer.print("\n");
    printer.print("Current states of the ships: \n");
    for (int j = 0; j < ship_manager.GetCountShips(); j++)
    {
        Ship ship = ship_manager[j];
        printer.print("Ship id: " + std::to_string(j) + "\n");
        if (ship.GetOrientation() == VERTICAL)
        {
            for (int i = 0; i < ship.GetLen(); i++)
            {

                char ch = static_cast<char>(ship.GetSegments()[i]);
                std::string str(1, ch);
                printer.print(str + "\n");
   
            }
            printer.print("\n");
        }
        else if (ship.GetOrientation() == HORIZONTAL)
        {
            for (int i = 0; i < ship.GetLen(); i++)
            {
                char ch = static_cast<char>(ship.GetSegments()[i]);
                std::string str(1, ch);
                printer.print(str + " ");
            }
            printer.print("\n");
        }
    }
}