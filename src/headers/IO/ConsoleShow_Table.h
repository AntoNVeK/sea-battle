#ifndef CONSOLE_SHOW_TABLE_H
#define CONSOLE_SHOW_TABLE_H

#include <iostream>
#include <utility>
#include "../ManagerShips.h"
#include "../Table.h"

class ConsoleShow_Table
{
public:
    void showTable(Table& table, bool flag);
    void showShips(ManagerShips& ship_manager);
};

#endif