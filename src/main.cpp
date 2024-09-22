#include <iostream>
#include <string>
#include <vector>
#include "./headers/Table.h"


int main()
{
    ManagerShips manager({ONE, TWO, TWO, THREE, FOUR});
    Table table(10, 10, manager);
    return 0;
}