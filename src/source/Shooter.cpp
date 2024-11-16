#include "../headers/Shooter.h"


Shooter::Shooter(Table& table) : table(table)
{
    state = DoubleAttackState::OFF;
}

void Shooter::operator()(Coord coord)
{
    if (state == DoubleAttackState::ON)
    {
        
        attack(coord, 2);

        state = DoubleAttackState::OFF;
        
    }
    else
    {
        attack(coord, 1);
    }
}

void Shooter::SetState(DoubleAttackState state)
{
    this->state = state;
}


void Shooter::attack(Coord coord, int count_attack)
{
    for (int i = 0; i < count_attack; i++){

        table.shoot(coord);

    }
}