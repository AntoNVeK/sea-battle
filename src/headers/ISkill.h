#ifndef ISKILL_H
#define ISKILL_H
#include "Table.h"
#include "Coord.h"

class Table;

class ISkill
{
public:
    virtual void use(Table& table) = 0;

    virtual void use(Table& table, const Coord& coord) = 0;

    virtual void use(Table& table, int x, int y) = 0;

    virtual ~ISkill() {};
};



#endif