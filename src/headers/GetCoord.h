#ifndef GETCOORD_H
#define GETCOORD_H
#include "Command.h"
#include "CoordSkillUse.h"

class GetCoord : public Command
{
public:
    GetCoord(CoordSkillUse coord);

    Coord get_coord() override;

    ~GetCoord() override = default;
private:
    CoordSkillUse* coord;
};



#endif