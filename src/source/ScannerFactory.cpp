#include "../headers/ScannerFactory.h"

ScannerFactory::ScannerFactory(SkillResult& results, std::shared_ptr<Command> command, Table& table) : results(results), command(command), table(table)
{}

std::shared_ptr<ISkill> ScannerFactory::create()
{
    Coord coord = command->get_coord();

    return std::make_shared<Scanner>(coord, results, table);
}


SkillName ScannerFactory::GetName() const
{
    return SkillName::Scanner;
}