#include "../headers/DoubleAttackFactory.h"

DoubleAttackFactory::DoubleAttackFactory(SkillResult& results, std::shared_ptr<Command> command, Table& table) : results(results), command(command), table(table)
{}

std::shared_ptr<ISkill> DoubleAttackFactory::create()
{
    Coord coord = command->get_coord();

    return std::make_shared<DoubleAttack>(coord, results, table);
}


SkillName DoubleAttackFactory::GetName() const
{
    return SkillName::DoubleAttack;
}