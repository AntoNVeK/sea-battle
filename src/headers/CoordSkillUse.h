#ifndef COORDSKILLUSE_H
#define COORDSKILLUSE_H
#include "Coord.h"


class CoordSkillUse
{
public:

    void SetCoord(Coord coord);

    const Coord& get_coord();

    ~CoordSkillUse() = default;

private:
    Coord coord;

};

#endif