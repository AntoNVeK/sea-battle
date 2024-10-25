#ifndef DOUBLEATTACKFACTORY_H
#define DOUBLEATTACKFACTORY_H
#include "ISkillFactory.h"
#include "DoubleAttack.h"

class DoubleAttackFactory : public ISkillFactory
{
public:
    DoubleAttackFactory(SkillResult& results);

    std::shared_ptr<ISkill> create() override;

    SkillName GetName() const override;

    ~DoubleAttackFactory() override = default;
private:
    SkillResult& results;
};




#endif