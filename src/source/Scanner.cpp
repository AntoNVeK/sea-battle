#include "../headers/Scanner.h"


Scanner::Scanner() {}


void Scanner::use(Table& table, const Coord& coord)
{
    
    for(int j = coord.GetY() - 1; j < coord.GetY() + 1; j++)
    {
        for(int i = coord.GetX() - 1; i < coord.GetX() + 1; i++){
                   
            if (table._cells[j][i] != SHIP)
            {
                std::cout << static_cast<char>(table._cells[j][i]);
            }
            else
            {
                std::cout << static_cast<char>(table.GetStateSegmentShip(i, j));
            }
            
            std::cout << " ";
        }
        std::cout << "\n";
    }


}

void Scanner::use(Table& table, int x, int y)
{
    this->use(table, Coord(x, y));
}

void Scanner::use(Table& table)
{
    this->use(table, Coord(1, 1));
}