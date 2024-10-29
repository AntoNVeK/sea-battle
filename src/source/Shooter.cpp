#include "../headers/Shooter.h"


Shooter::Shooter(Table& table) : table(table)
{
    state = DoubleAttackState::OFF;
}

void Shooter::operator()(Coord coord)
{
    if (state == DoubleAttackState::ON)
    {
        if (table.shoot(coord))
        {
            table.shoot(coord);

            state = DoubleAttackState::OFF;
        }
    }
    else
    {
        table.shoot(coord);
    }
}

void Shooter::SetState(DoubleAttackState state)
{
    this->state = state;
}