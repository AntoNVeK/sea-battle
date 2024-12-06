#ifndef CONSOLE_SHOW_TABLE_H
#define CONSOLE_SHOW_TABLE_H

#include <iostream>
#include <utility>
#include <iomanip>
#include "../ManagerShips.h"
#include "../Table.h"
#include "ConsolePrinterMessage.h"

class ConsoleShow_Table
{
private:
    ConsolePrinterMessage printer;
public:
    void showTable(Table& table, bool flag);
    void showShips(ManagerShips& ship_manager);
};

#endif