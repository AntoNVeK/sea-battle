#ifndef SCANNERFACTORY_H
#define SCANNERFACTORY_H
#include "ISkillFactory.h"
#include "Scanner.h"
#include "SkillResult.h"

class ScannerFactory : public ISkillFactory
{
public:
    ScannerFactory(SkillResult& results);

    std::shared_ptr<ISkill> create(Coord coord) override;

    SkillName GetName() const override;

    ~ScannerFactory() override = default;
private:
    SkillResult& results;
};




#endif