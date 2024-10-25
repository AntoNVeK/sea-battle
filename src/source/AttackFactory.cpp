#include "../headers/AttackFactory.h"

AttackFactory::AttackFactory()
{}

std::shared_ptr<ISkill> AttackFactory::create(Coord coord)
{
    return std::make_shared<Attack>();
}



SkillName AttackFactory::GetName() const
{
    return SkillName::Attack;
}
