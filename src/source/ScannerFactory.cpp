#include "../headers/ScannerFactory.h"

ScannerFactory::ScannerFactory(SkillResult& results) : results(results)
{}

std::shared_ptr<ISkill> ScannerFactory::create(Coord coord)
{
    
    return std::make_shared<Scanner>(coord, results);
}


SkillName ScannerFactory::GetName() const
{
    return SkillName::Scanner;
}