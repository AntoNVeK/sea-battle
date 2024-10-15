#ifndef SCANNERFACTORY_H
#define SCANNERFACTORY_H
#include "ISkillFactory.h"
#include "Scanner.h"

class ScannerFactory : public ISkillFactory
{
public:

    std::shared_ptr<ISkill> create(int x = 0, int y = 0) override;

    std::string GetName() const override;

    ~ScannerFactory() override = default;

};




#endif