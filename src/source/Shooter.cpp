#include "../headers/Shooter.h"


Shooter::Shooter(Table& table) : table(table)
{
    state = DoubleAttackState::OFF;
}

bool Shooter::operator()(Coord coord)
{
    if (state == DoubleAttackState::ON)
    {
        

        state = DoubleAttackState::OFF;
        
        return attack(coord, 2);
    }
    else
    {
        return attack(coord, 1);
    }
}

void Shooter::SetState(DoubleAttackState state)
{
    this->state = state;
}


bool Shooter::attack(Coord coord, int count_attack)
{
    bool flag = false;
    for (int i = 0; i < count_attack; i++){
        if (i == 0)
        {
            flag = table.shoot(coord);
        }
        else
        {
            table.shoot(coord);
        }
    }
    return flag;
}



bool Shooter::DoubleAttack() const
{
    return state == DoubleAttackState::ON ? true : false;
}


Shooter::Shooter(const Shooter &other) : state(other.state), table(other.table)
{

}


Shooter::Shooter(Shooter &&other) : state(other.state), table(other.table)
{
    
}
Shooter& Shooter::operator=(const Shooter &other)
{
    if (this != &other)
        {
            this->state = other.state;
            this->table = other.table;
        }
    return *this;
}
Shooter& Shooter::operator=(Shooter &&other)
{
    if (this != &other)
        {
            this->state = other.state;
            this->table = other.table;
        }
    return *this;
}



