#include "../headers/GetCoord.h"

GetCoord::GetCoord(Coord& coord) : coord(coord)
{

}


Coord GetCoord::operator()()
{
    return coord;
}