#include "../headers/DoubleAttackFactory.h"

DoubleAttackFactory::DoubleAttackFactory(SkillResult& results, Shooter& shooter) : results(results), shooter(shooter)
{}

std::shared_ptr<ISkill> DoubleAttackFactory::create()
{
    return std::make_shared<DoubleAttack>(results, shooter);
}


SkillName DoubleAttackFactory::GetName() const
{
    return SkillName::DoubleAttack;
}