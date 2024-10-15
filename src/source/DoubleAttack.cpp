#include "../headers/DoubleAttack.h"

DoubleAttack::DoubleAttack(int x, int y) : _x(x), _y(y) {}

void DoubleAttack::use(Table& table)
{
    table.shoot(_x, _y);

    try
    {
        table.shoot(_x, _y);
    }
    catch(...)
    {
        std::cout << "Ship already destroyed" << "\n";
    }
}


void DoubleAttack::install_reaction(std::function<void(ScannerResult state)> func)
{

}




