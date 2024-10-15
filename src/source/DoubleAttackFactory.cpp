#include "../headers/DoubleAttackFactory.h"


std::shared_ptr<ISkill> DoubleAttackFactory::create(int x, int y)
{
    return std::make_shared<DoubleAttack>(x, y);
}


std::string DoubleAttackFactory::GetName() const
{
    return "DoubleAttack";
}