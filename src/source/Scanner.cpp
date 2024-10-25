#include "../headers/Scanner.h"


Scanner::Scanner(Coord coord, SkillResult& results) : coord(coord), results(results)
{
    if (coord.GetX() < 1 || coord.GetY() < 1)
    {
        throw std::invalid_argument("invalid arguments");
    }
}

void Scanner::use(Table& table)
{
    for(int j = coord.GetY() - 1; j < coord.GetY() + 1; j++)
    {
        for(int i = coord.GetX() - 1; i < coord.GetX() + 1; i++){
                   
            if (table._cells[j][i] == SHIP)
            {
                results.add_result(200, "Ship found");
                return;
            }
            
        }

    }
    results.add_result(404, "Ship not found");
}


