#include "../headers/AttackFactory.h"


std::shared_ptr<ISkill> AttackFactory::create(int x, int y)
{
    return std::make_shared<Attack>();
}



std::string AttackFactory::GetName() const
{
    return "Attack";
}