#include "../headers/Scanner.h"


Scanner::Scanner(int x, int y) : _x(x), _y(y) {}

void Scanner::use(Table& table)
{
    for(int j = _y - 1; j < _y + 1; j++)
    {
        for(int i = _x - 1; i < _x + 1; i++){
                   
            if (table._cells[j][i] == SHIP)
            {
                _reaction();
                return;
            }
            
        }

    }
}


void Scanner::install_reaction(std::function<void()> func)
{
    this->_reaction = func;
}



