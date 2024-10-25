#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <iterator>
#include "./headers/Table.h"
#include "./headers/ManagerSkills.h"
#include "./headers/ManagerShips.h"
#include "./headers/Ship.h"
#include "./headers/SkillResult.h"
#include "headers/skill_name.h"


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

    ManagerSkills manager;

    Table table(&manager);

    ManagerShips managerships({TWO, THREE, FOUR});

    managerships[0].SetOrientation(VERTICAL);

    table.add_ship(managerships[0], 3, 4);

    table.shoot(3, 4);

    {
        auto factory = manager.GetFront();
        
        auto skill = factory->create(Coord(3, 4));

        std::cout << factory->GetName() << "\n";

        skill->use(table);

        auto result = manager.GetResults();
        if (!result.empty())
            std::cout << result.GetLast() << "\n";

    
    }

    for (int i = 0; i < managerships[0].GetLen(); i++)
    {
        std::cout << static_cast<char>(managerships[0].GetSegments()[i]) << "\n";
    }

    print(table);

    return 0;

}