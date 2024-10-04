#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include "./headers/Table.h"
#include "./headers/ManagerSkillsObserver.h"
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

    ManagerSkillsObserver observer(manager);

    Table table(observer);

    ManagerShips managerships({TWO});

    table.add_ship(managerships[0], 1, 1);

    table.shoot(1, 1);
    table.shoot(1, 1);
    table.shoot(2, 1);
    table.shoot(2, 1);

    table.shoot(10, 1);

    print(table);


    return 0;
}