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
#include "./headers/skill_name.h"
#include "./headers/Command.h"
#include "./headers/GetCoord.h"


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
    Table table;

    ManagerShips managerships({TWO, THREE, FOUR});

    Coord skillcoord;

    SkillResult results;

    std::shared_ptr<Command> command = std::make_shared<GetCoord>(skillcoord);
    
    SkillFactory skillfactory(results, command, table, managerships);

    ManagerSkills manager(skillfactory);

    table.SetObserver(&manager);

    managerships[0].SetOrientation(VERTICAL);

    table.add_ship(managerships[0], 3, 4);

    {
        skillcoord = Coord(3, 4);

        auto factory = manager.GetFront();
        
        auto skill = factory->create();

        std::cout << factory->GetName() << "\n";

        skill->use();

        if (!results.empty())
            std::cout << results.GetLast() << "\n";

    
    }
    table.shoot(3, 5);
    table.shoot(3, 5);

    for (int i = 0; i < managerships[0].GetLen(); i++)
    {
        std::cout << static_cast<char>(managerships[0].GetSegments()[i]) << "\n";
    }

    print(table);

    return 0;

}