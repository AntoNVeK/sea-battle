#include "../headers/AttackFactory.h"

AttackFactory::AttackFactory(SkillResult& results) : results(results)
{}

std::shared_ptr<ISkill> AttackFactory::create(Coord coord)
{
    return std::make_shared<Attack>(results);
}



SkillName AttackFactory::GetName() const
{
    return SkillName::Attack;
}
