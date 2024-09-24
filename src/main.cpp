#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include "./headers/Table.h"


int main()
{
    std::vector<Length> vec;

    int count = -1;

    for (int i = 1; i < 5; i++)
    {
        std::cout << "How many make ships length: " << i << "\n";
        std::cin >> count;
        for (int j = 0; j < count; j++)
        {
            vec.push_back((Length)i);
        }
    }
    int x, y;
    std::cout << "Print size Table" << "\n";
    std::cin >> x >> y;
    ManagerShips manager(vec);
    Table table(x, y, manager);



    system("cls");
    int i = 0;
    for (; i < manager.GetCountShips();)
    {   
        std::cout << "_cells" << "\n";
        table.print(table.GetCells());
        std::cout << "_hidden_cells" << "\n";
        table.print(table.GetHiddenCells());
        
        int x = 0;
        int y = 0;
        int _or = -1;
        Orientation orie;
        while (x <= 0 || y <= 0 || _or < 0 || _or > 1)
        {
            
            std::cout << "Enter the location of the Ship HORIZONTAL : 0 VERTICAL : 1" << "\n";
            std::cin >> _or;

            if (_or < 0 || _or > 1)
            {
                std::cout << "Bad location try again" << "\n";
                continue;
            }
            orie = (_or == 1) ? VERTICAL : HORIZONTAL;

            std::cout << "Enter the coordinates of the ship's starting points separated by a space and its length: " << manager[i].GetLen() << "\n";
            std::cin >> x >> y;
            
            if (!table.check_point({x, y}))
            {
                std::cout << "Try again" << "\n";
                continue;
            }
            std::cout << "______________________________________________________" << "\n";
            manager[i].SetOrientation(orie);
            if (!table.add_ship(manager[i], {x, y}))
            {
                std::cout << "Try again" << "\n";
                continue;
            }
            i++;
        }
        std::cout << "_cells" << "\n";
        table.print(table.GetCells());
        std::cout << "_hidden_cells" << "\n";
        table.print(table.GetHiddenCells());
        getchar();
        getchar();
        system("cls");
    }

    std::cout << "_cells" << "\n";
    table.print(table.GetCells());
    std::cout << "_hidden_cells" << "\n";
    table.print(table.GetHiddenCells());

    table.shoot({2,2});
    table.shoot({2,2});
    table.shoot({2,3});
    
    std::cout << "_cells" << "\n";
    table.print(table.GetCells());
    std::cout << "_hidden_cells" << "\n";
    table.print(table.GetHiddenCells());
    
    return 0;
}