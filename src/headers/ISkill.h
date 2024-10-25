#ifndef ISKILL_H
#define ISKILL_H
#include <functional>
#include "SkillResult.h"

class Table;
class Coord;


class ISkill
{

public:

    virtual void use(Table& table) = 0;

    virtual ~ISkill() = 0;

};



#endif