#include "../headers/ScannerFactory.h"



std::shared_ptr<ISkill> ScannerFactory::create(int x, int y)
{
    return std::make_shared<Scanner>(x, y);
}


std::string ScannerFactory::GetName() const
{
    return "Scanner";
}