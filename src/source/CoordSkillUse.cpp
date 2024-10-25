#include "../headers/CoordSkillUse.h"


void CoordSkillUse::SetCoord(Coord coord)
{
    this->coord = coord;
}


const Coord& CoordSkillUse::get_coord()
{
    return coord;
}