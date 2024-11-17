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
#include "./headers/GetCoord.h"
#include "nlohmann/json.hpp"
#include "./headers/Serializers/ManagerSkillsSerializer.h"
#include "./headers/Serializers/ShooterSerializer.h"
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

    
    
    Table table;

    Shooter shooter(table);
    
    ManagerShips managerships({TWO});

    Coord skillcoord;

    SkillResult results;

    GetCoord command(skillcoord);
    
    SkillFactory skillfactory(results, command, table, managerships, shooter);

    ManagerSkills manager(skillfactory);


    ManagerSkillsSerializer s(manager);

    s.load();

    json j = s.get();
    

    std::cout << j << std::endl;

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

        manager.delete_skill();

        skillcoord = Coord();
    
    }
    ShooterSerializer s1(shooter);

    s1.load();

    json j1 = s1.get();
    

    std::cout << j1 << std::endl;

    
    shooter(Coord(3, 5));

    shooter(Coord(3, 4));
    
    for (int i = 0; i < managerships[0].GetLen(); i++)
    {
        std::cout << static_cast<char>(managerships[0].GetSegments()[i]) << "\n";
    }

    print(table);



    return 0;

}