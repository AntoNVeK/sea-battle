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

    bool operator()(Coord coord);

    void SetState(DoubleAttackState state);
    
    bool DoubleAttack() const;


    Shooter(const Shooter &other);
    Shooter(Shooter &&other);

    Shooter& operator=(const Shooter &other);
    Shooter& operator=(Shooter &&other);

private:
    bool attack(Coord coord,int count_attack);
};

#endif