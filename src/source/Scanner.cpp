#include "../headers/Scanner.h"


Scanner::Scanner(Coord coord, SkillResult& results, Table& table) : coord(coord), results(results), table(table)
{
    if (coord.GetX() < 1 || coord.GetY() < 1)
    {
        throw std::invalid_argument("invalid arguments");
    }
}

void Scanner::use()
{
    for(int j = coord.GetY() - 1; j < coord.GetY() + 1; j++)
    {
        for(int i = coord.GetX() - 1; i < coord.GetX() + 1; i++){
                   
            if (table.GetCoords()[j][i] == SHIP)
            {
                results.add_result("Ship found");
                return;
            }
            
        }

    }
    results.add_result("Ship not found");
}


