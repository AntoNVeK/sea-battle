#include "../headers/GetCoord.h"

GetCoord::GetCoord(CoordSkillUse coord) : coord(&coord)
{

}


Coord GetCoord::get_coord()
{
    return coord->get_coord();
}