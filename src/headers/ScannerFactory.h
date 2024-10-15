#ifndef SCANNERFACTORY_H
#define SCANNERFACTORY_H
#include "ISkillFactory.h"

class ScannerFactory : public ISkillFactory
{
public:

    ISkill* create() override;

    ISkill* create(int x, int y) override;

    std::string GetName() const override;

    ~ScannerFactory() override = default;

};




#endif