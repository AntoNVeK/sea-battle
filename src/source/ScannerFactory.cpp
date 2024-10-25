#include "../headers/ScannerFactory.h"

ScannerFactory::ScannerFactory(SkillResult& results, std::shared_ptr<Command> command) : results(results), command(command)
{}

std::shared_ptr<ISkill> ScannerFactory::create()
{
    Coord coord = command->get_coord();

    return std::make_shared<Scanner>(coord, results);
}


SkillName ScannerFactory::GetName() const
{
    return SkillName::Scanner;
}