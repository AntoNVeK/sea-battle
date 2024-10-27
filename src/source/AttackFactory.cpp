#include "../headers/AttackFactory.h"

AttackFactory::AttackFactory(ManagerShips& manager) : manager(manager)
{}

std::shared_ptr<ISkill> AttackFactory::create()
{
    return std::make_shared<Attack>(manager);
}



SkillName AttackFactory::GetName() const
{
    return SkillName::Attack;
}
