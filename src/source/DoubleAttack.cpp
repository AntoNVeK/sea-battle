#include "../headers/DoubleAttack.h"



DoubleAttack::DoubleAttack() {};





void DoubleAttack::use(Table& table, const Coord& coord)
{
    table.shoot(coord);

    try
    {
        table.shoot(coord);
    }
    catch(...)
    {
        std::cout << "Ship already destroyed" << "\n";
    }
}




void DoubleAttack::use(Table& table, int x, int y)
{
    return this->use(table, Coord(x, y));
}


void DoubleAttack::use(Table& table)
{
    return this->use(table, Coord(1, 1));
}