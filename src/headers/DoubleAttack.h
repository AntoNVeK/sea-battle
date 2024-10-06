#ifndef DOUBLEATTACK_H
#define DOUBLEATTACK_H
#include "Table.h"
#include "Coord.h"


class DoubleAttack : public ISkill
{
public:
    DoubleAttack();

    void use(Table& table) override;

    void use(Table& table, int x, int y) override;

    void use(Table& table, const Coord& coord) override;

};


#endif