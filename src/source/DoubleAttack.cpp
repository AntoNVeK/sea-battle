#include "../headers/DoubleAttack.h"

DoubleAttack::DoubleAttack() {}

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
    this->use(table, Coord(x, y));
}


void DoubleAttack::use(Table& table)
{
    throw std::invalid_argument("incorrect arguments");
}


void DoubleAttack::install_reaction(std::function<void()> func)
{

}




