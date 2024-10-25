#include "../headers/DoubleAttackFactory.h"

DoubleAttackFactory::DoubleAttackFactory(SkillResult& results) : results(results)
{}

std::shared_ptr<ISkill> DoubleAttackFactory::create(Coord coord)
{
    return std::make_shared<DoubleAttack>(coord, results);
}


SkillName DoubleAttackFactory::GetName() const
{
    return SkillName::DoubleAttack;
}