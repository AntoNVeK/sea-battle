#include "../headers/DoubleAttackFactory.h"

DoubleAttackFactory::DoubleAttackFactory(SkillResult& results, std::shared_ptr<Command> command) : results(results), command(command)
{}

std::shared_ptr<ISkill> DoubleAttackFactory::create()
{
    Coord coord = command->get_coord();

    return std::make_shared<DoubleAttack>(coord, results);
}


SkillName DoubleAttackFactory::GetName() const
{
    return SkillName::DoubleAttack;
}