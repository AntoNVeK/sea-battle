#ifndef SCANNERFACTORY_H
#define SCANNERFACTORY_H
#include "ISkillFactory.h"
#include "Scanner.h"
#include "SkillResult.h"
#include "GetCoord.h"

class ScannerFactory : public ISkillFactory
{
public:
    ScannerFactory(SkillResult& results, GetCoord& command, Table& table);

    std::shared_ptr<ISkill> create() override;

    SkillName GetName() const override;

    ~ScannerFactory() override = default;
private:
    SkillResult& results;
    GetCoord& command;
    Table& table;
};




#endif