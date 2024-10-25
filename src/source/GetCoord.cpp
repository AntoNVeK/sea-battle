#include "../headers/GetCoord.h"

GetCoord::GetCoord(Coord& coord) : coord(coord)
{

}


Coord GetCoord::get_coord()
{
    return coord;
}