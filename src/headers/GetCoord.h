#ifndef GETCOORD_H
#define GETCOORD_H
#include "Command.h"


class GetCoord : public Command
{
public:
    GetCoord(Coord& coord);

    Coord get_coord() override;

    ~GetCoord() override = default;
private:
    Coord& coord;
};



#endif