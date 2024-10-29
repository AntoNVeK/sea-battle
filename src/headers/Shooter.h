#ifndef SHOOTER_H
#define SHOOTER_H
#include "DoubleAttackState.h"
#include "Table.h"
#include "Coord.h"

class Shooter
{
private:
    DoubleAttackState state;
    Table& table;

public:
    Shooter(Table& table);

    void operator()(Coord coord);

    void SetState(DoubleAttackState state);
    
};

#endif