#ifndef SCANNERFACTORY_H
#define SCANNERFACTORY_H
#include "ISkillFactory.h"
#include "Scanner.h"
#include "SkillResult.h"
#include "Command.h"

class ScannerFactory : public ISkillFactory
{
public:
    ScannerFactory(SkillResult& results, std::shared_ptr<Command> command);

    std::shared_ptr<ISkill> create() override;

    SkillName GetName() const override;

    ~ScannerFactory() override = default;
private:
    SkillResult& results;
    std::shared_ptr<Command> command;
};




#endif