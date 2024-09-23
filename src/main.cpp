#include <iostream>
#include <string>
#include <vector>
#include "./headers/Table.h"


int main()
{
    ManagerShips manager({ONE, TWO, TWO, THREE, FOUR});
    Table table(10, 10, manager);
    table.put_ships();
    return 0;
}