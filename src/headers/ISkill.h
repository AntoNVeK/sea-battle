#ifndef ISKILL_H
#define ISKILL_H
#include "Table.h"
class ISkill
{
public:
    virtual void use(Table& table);

    virtual void use(Table& table, const Coord& coord);

    virtual void use(Table& table, int x, int y);

    virtual ~ISkill() {};
};



#endif