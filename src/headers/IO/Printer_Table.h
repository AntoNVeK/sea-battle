#ifndef PRINTER_TABLE_H
#define PRINTER_TABLE_H
#include <iostream>
#include <utility>
#include "../game.h"
#include "ConsoleShow_Table.h"

class Printer_Table
{
public:
    void drawGameTable(Game &game);
    void showShips(Game &game, bool flag);
    void showTableShips(Game &game, bool flag);
    void showTable(Game &game, bool flag);
};

#endif