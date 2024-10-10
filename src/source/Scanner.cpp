#include "../headers/Scanner.h"


Scanner::Scanner() {}


void Scanner::use(Table& table, const Coord& coord)
{

    for(int j = coord.GetY() - 1; j < coord.GetY() + 1; j++)
    {
        for(int i = coord.GetX() - 1; i < coord.GetX() + 1; i++){
                   
            if (table._cells[j][i] == SHIP)
            {
                _reaction();
                return;
            }
            
        }

    }


}

void Scanner::use(Table& table, int x, int y)
{
    this->use(table, Coord(x, y));
}

void Scanner::use(Table& table)
{
    throw std::invalid_argument("incorrect arguments");
}


void Scanner::install_reaction(std::function<void()> func)
{
    this->_reaction = func;
}



