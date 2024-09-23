#include <iostream>
#include <string>
#include <vector>
#include "./headers/Table.h"


int main()
{
    ManagerShips manager({});
    Table table(10, 10, manager);
    table.put_ships();


        
   // int i = 0;
   // for (; i < manager.GetCountShips();)
   // {
   //     int x = 0;
   //     int y = 0;
   //     int _or = -1;
   //     Orientation orie;
   //     while (x <= 0 || y <= 0 || _or < 0 || _or > 1)
   //     {
   //         
   //         std::cout << "Enter the location of the Ship HORIZONTAL : 0 VERTICAL : 1" << "\n";
   //         std::cin >> _or;
//
   //         if (_or < 0 || _or > 1)
   //         {
   //             std::cout << "Bad location try again" << "\n";
   //             continue;
   //         }
   //         orie = (_or == 1) ? VERTICAL : HORIZONTAL;
//
   //         std::cout << "Enter the coordinates of the ship's starting points separated by a space and its length: " << manager[i].GetLen() << "\n";
   //         std::cin >> x >> y;
   //         
   //         if (!check_point({x, y}))
   //         {
   //             std::cout << "Try again" << "\n";
   //             continue;
   //         }
   //         std::cout << "______________________________________________________" << "\n";
   //         manager[i].SetOrientation(orie);
   //         if (!this->add_ship_map(manager[i], {x, y}))
   //         {
   //             std::cout << "Try again" << "\n";
   //             continue;
   //         }
   //         i++;
   //     }
   //     this->print();
//
   // }
    return 0;
}