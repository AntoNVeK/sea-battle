#ifndef GETCOORD_H
#define GETCOORD_H
#include "Coord.h"


class GetCoord
{
public:
    GetCoord(Coord& coord);

    Coord operator()();

    ~GetCoord() = default;
private:
    Coord& coord;
};



#endif