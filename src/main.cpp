#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <iterator>
#include "./headers/Table.h"
#include "./headers/ManagerSkills.h"
#include "./headers/ManagerShips.h"
#include "./headers/Ship.h"



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



int main()
{    
    ManagerSkills manager;

    Table table(&manager);

    ManagerShips managerships({TWO, THREE, FOUR});

    managerships[0].SetOrientation(VERTICAL);

    table.add_ship(managerships[0], 3, 4);
    table.add_ship(managerships[1], 8, 1);
    table.add_ship(managerships[2], 1, 10);

    auto factory = manager.GetFront();

    auto skill = factory->create(3, 4);

    std::cout << factory->GetName() << "\n";

    ScannerResult flag = ScannerResult::null;

    skill->install_reaction([&flag](ScannerResult state){
        if (state == ScannerResult::ISSHIP)
            flag = ScannerResult::ISSHIP;
        else if (state == ScannerResult::NOSHIP)
            flag = ScannerResult::NOSHIP;    
    });
    skill->use(table);

    if (flag == ScannerResult::ISSHIP)
        std::cout << "scanner found ship" << "\n";
    else if (flag == ScannerResult::NOSHIP)
        std::cout << "scanner not found ship" << "\n";
    print(table);

    return 0;
}